#include "simplex.h"

simplex::Simplex::Simplex(int var, int res, double *C, double *B, double **A,bool min, char *EQ)
{
	this->var=var;
	this->res=res;
	this->min=min;
	this->result=this->resultPrev=this->iteration=0;

	this->C.assign(C,C+this->var);
	this->B.assign(B,B+this->res);
	this->EQ.assign(EQ,EQ+this->res);

	this->A.resize(extents[this->res][this->var]);

	for(int i=0;i<res;++i)
	for(int j=0;j<var;++j)
		this->A[i][j]=A[i][j];

	this->Basis=std::vector<unsigned int>(this->res,0);
	this->CBasis=std::vector<double>(this->res,0);
	this->Teta=std::vector<double>(this->res,0);
	this->Plan=std::vector<double>(this->res,0);


	calculateM();
	normalize();
	makeBasis();

	this->BasicPlan=std::vector<double>(this->var,0);

}

void simplex::Simplex::calculateM()
{
    M=0.0;
    for(int i=0; i<res; ++i)
    {
		if(M<B[i])
			M=B[i];
		for(int j=0; j<var; ++j)
			if(M<A[i][j])
				M=A[i][j];
    }

	for(int i=0; i<var; ++i)
		if(M<C[i])
			M=C[i];

	if(min==true)
		M*=1000;
	else
		M*=-1000;
}

void simplex::Simplex::normalize()
{
//	if(!min)
//	{
//		for(int i=0; i<var; ++i)
//			C[i]*=-1;
//		min=true;
//	}

	// B>=0
	for(int i=0; i<res; ++i)
	{
		if(B[i]<0)
		{
			B[i]*=-1;
			for(int j=0;j<var;++j)
				A[i][j]*=-1;
		}
	}
	// переход к равенству
	for(int i=0; i<res; ++i)
	{
		if(EQ[i]!=EQUAL)
		{
			var++;
			C.push_back(0);
			A.resize(extents[res][var]);
			if(EQ[i]>EQUAL)
				A[i][var-1]=-1;
			else
				A[i][var-1]=+1;
		}
	}
}

void simplex::Simplex::makeBasis()
{
	for(int i=0; i<res; ++i)
	{
		var++;
		C.push_back(M);
		A.resize(extents[res][var]);
		A[i][var-1]=+1;
		Basis[i]=var-1;
		CBasis[i]=C[Basis[i]];
	}
}

void simplex::Simplex::view()
{
	std::cout<<std::endl;
	for(int i=0;i<var;++i)
		std::cout<<"C["<<i+1<<"]="<<this->C[i]<<" ";

	std::cout<<std::endl<<std::endl;;
	for(int i=0;i<res;++i)
	{
		for(int j=0;j<var;++j)
			std::cout<<"A["<<i+1<<","<<j+1<<"]="<<this->A[i][j]<<"  ";
		std::cout<<std::endl;
	}

	std::cout<<std::endl;
	for(int i=0;i<res;++i)
		std::cout<<"B["<<i+1<<"]="<<this->B[i]<<" ";

	std::cout<<std::endl<<std::endl;
	for(int i=0;i<res;++i)
		std::cout<<"Basis["<<i+1<<"]="<<this->Basis[i]+1<<" ";

	std::cout<<std::endl<<std::endl;
	for(int i=0;i<res;++i)
		std::cout<<"CBasis["<<i+1<<"]="<<this->CBasis[i]<<" ";

	std::cout<<std::endl<<std::endl;
	for(int i=0;i<res;++i)
		std::cout<<"Plan["<<i+1<<"]="<<this->Plan[i]<<" ";

	std::cout<<std::endl<<std::endl;
	for(int i=0;i<res;++i)
		std::cout<<"BasicPlan["<<i+1<<"]="<<this->BasicPlan[i]<<" ";

	std::cout<<std::endl<<std::endl;
	for(int i=0;i<res;++i)
		std::cout<<"Teta["<<i+1<<"]="<<this->Teta[i]<<" ";

	std::cout<<std::endl<<std::endl;
	std::cout<<"result="<<this->result<<" ";
	std::cout<<"resultPrev="<<this->resultPrev<<" ";
}

int simplex::Simplex::solve()
{
	do{
		calculateBasicPlan();
		unsigned int leave=leaveBasis();
		calculateTeta(leave);
		unsigned int come=comeBasis();
		makeNewSTable(leave,come);
        std::cout<<"iteration "<<iteration<<std::endl; //fixme
        //view(); //fixme
		iteration++;
	}
    while(!isOptimal() && iteration<1);
	return 0;
}

bool simplex::Simplex::isOptimal()
{
	bool result=true;

	for(int i=0; i<var; ++i)
		if(BasicPlan[i]>0)
			result=false;

	if(min)
		return result;
	return !result;
}

void simplex::Simplex::calculateBasicPlan()
{
	for(int i=0; i<var; ++i)
	{
		BasicPlan[i]=0;
		for(int j=0; j<res; ++j)
			BasicPlan[i]+=A[j][i]*CBasis[j]; //DEBUGME
		BasicPlan[i]-=C[i];
	}
}

unsigned int simplex::Simplex::leaveBasis()
{
	unsigned int result=0;

	for(int i=1; i<var; i++)
		if(min)
		{
			if(BasicPlan[i]>BasicPlan[result])
				result=i;
		}
		else
		{
			if(BasicPlan[i]<BasicPlan[result])
				result=i;
		}

	return result;
}

unsigned int simplex::Simplex::comeBasis()
{
	unsigned int result;
	for(int i=0; i<res; ++i)
		if(Teta[i]>0)
		{
			result=i;
			break;
		}

	for(int i=0; i<res; ++i)
		if(Teta[i]>Teta[result])
			result=i;

	return result;
}

void simplex::Simplex::calculateTeta(unsigned int divider)
{
	for(int i=0; i<res; ++i)
		Teta[i]=Plan[i]/A[divider][i];
}

void simplex::Simplex::makeNewSTable(unsigned int leave, unsigned int come)
{
    double div=A[come][leave];
    for(int i=0;i<var; ++i)
        A[come][i]/=div;
    for(int i=0; i<res; ++i)
    {
        //std::cout<<leave<<std::endl; //fixme
        //std::cout<<A[i][0]<<std::endl; //fixme
        A[i][leave]=0;
    }    

    view();
}

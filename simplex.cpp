#include "simplex.h"

simplex::Simplex::Simplex(int var, int res, double *C, double *B, double **A,bool min, char *EQ) //REVIEWED
{
	this->var=var;
	this->res=res;
	this->min=min;
	this->result=this->resultPrev=this->iteration=0;
        this->error=false;

	this->C.assign(C,C+this->var);
	this->B.assign(B,B+this->res);
	this->EQ.assign(EQ,EQ+this->res);

	this->A.resize(extents[this->res][this->var]);

	for(int i=0;i<res;++i)
	for(int j=0;j<var;++j)
		this->A[i][j]=A[i][j];

        this->Basis=std::vector<int>(this->res,0);
	this->CBasis=std::vector<double>(this->res,0);
	this->Teta=std::vector<double>(this->res,0);
	this->Plan=std::vector<double>(this->res,0);


	calculateM();
	normalize();
	makeBasis();

	this->BasicPlan=std::vector<double>(this->var,0);
        this->Plan=this->B;
}

void simplex::Simplex::calculateM() //REVIEWED
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
                M*=10000;
	else
                M*=-10000;
}

void simplex::Simplex::normalize()  //REVIEWED
{
//	if(!min)
//	{
//		for(int i=0; i<var; ++i)
//			C[i]*=-1;
//		min=true;
//	}

	// B>=0

        //щоб бэ було додатным
	for(int i=0; i<res; ++i)
	{
		if(B[i]<0)
		{
			B[i]*=-1;
			for(int j=0;j<var;++j)
                        {
                            A[i][j]*=-1;
                            EQ[i]*=-1; //fixme поменять знак неравенства //FIXED
                        }
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
                        EQ[i]=EQUAL;
		}
	}
}

void simplex::Simplex::makeBasis() //REVIEWED
{
	for(int i=0; i<res; ++i)
	{
		var++;
		C.push_back(M);
		A.resize(extents[res][var]);

                A[i][var-1]=1;
		Basis[i]=var-1;
		CBasis[i]=C[Basis[i]];
	}
}

void simplex::Simplex::view()  //SKIPED
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
        for(int i=0;i<var;++i)
		std::cout<<"BasicPlan["<<i+1<<"]="<<this->BasicPlan[i]<<" ";

	std::cout<<std::endl<<std::endl;
	for(int i=0;i<res;++i)
		std::cout<<"Teta["<<i+1<<"]="<<this->Teta[i]<<" ";
        std::cout<<"devider"<<comeBasis()<<" ";
        std::cout<<"leave"<<leaveBasis()<<" ";
        std::cout<<"Dividens ="<<A[leaveBasis()][comeBasis()]<<" ";
	std::cout<<std::endl<<std::endl;
	std::cout<<"result="<<this->result<<" ";
	std::cout<<"resultPrev="<<this->resultPrev<<" ";
}

void simplex::Simplex::calculateResult()
{
    result=0;
    for(int i=0; i<res; ++i)
        result+=Plan[i]*CBasis[i];
}

bool simplex::Simplex::solve()
{
	do{
		calculateBasicPlan();
        calculateResult();
        std::cout<<"RESULT="<<result<<std::endl; //fixme
		unsigned int come=comeBasis();
                calculateTeta(come);
                if(isError())
                    return error;

                unsigned int leave=leaveBasis();
                view();
                makeNewSTable(leave,come);
                std::cout<<"ITERATIJN№"<<iteration<<std::endl; //fixme
                iteration++;
	}
    while(!isOptimal() && iteration<10);
        return error;
}

bool simplex::Simplex::isOptimal() //REVIEWED
{
        bool result=true;

	for(int i=0; i<var; ++i)
                if(BasicPlan[i]>0)
			result=false;

	if(min)
		return result;
	return !result;
}

void simplex::Simplex::calculateBasicPlan() //REVIEWED
{
	for(int i=0; i<var; ++i)
	{
		BasicPlan[i]=0;
		for(int j=0; j<res; ++j)
                        BasicPlan[i]+=A[j][i]*CBasis[j];
		BasicPlan[i]-=C[i];
	}
}

int simplex::Simplex::comeBasis() //REVIEWED / fix by OSIPETKA
{
	unsigned int result=0;

	for(int i=1; i<var; i++)
		if(min)
		{
                        if((BasicPlan[i]>BasicPlan[result])&&(BasicPlan[i]!=0))
				result=i;
		}
		else
		{
                        if((BasicPlan[i]<BasicPlan[result])&&(BasicPlan[i]!=0))
				result=i;
		}

	return result;
}

int simplex::Simplex::leaveBasis() //REVIEWED / fix by OSIPETKA
{

 double temp=0;
 int maxElem = -1;

 for (int i=0; i<res; i++)
 {
  if ( (maxElem == -1) && (Teta[i]>0) )
  {
   temp = Teta[i];
   maxElem = i;
  }
  if ( (Teta[i]>0) && (Teta[i] < temp) )
  {
   temp = Teta[i];
   maxElem = i;
  }
 }

 return maxElem;
}



void simplex::Simplex::calculateTeta(int divider) //REVIEWED
{
	for(int i=0; i<res; ++i)
                Teta[i]=Plan[i]/A[i][divider];
}

void simplex::Simplex::makeNewSTable(int leave, int come) //REVIEWED / fix by OSIPETKA
{
    array2D newA;
    newA.resize(extents[this->res][this->var]);

    double div=A[leave][come];
    for(int i=0;i<var; ++i)
        newA[leave][i]=A[leave][i]/div;


    for(int i=0; i<res; ++i)
        newA[i][come]=0;
    newA[leave][come]=1;

    for( int i=0; i<res; ++i)
    for( int j=0; j<var; ++j)
    {
        if( (i!=leave)&&(j!=come) )
            newA[i][j]=(div*A[i][j]-A[i][come]*A[leave][j])/div;  //DEBUGME
    }

    std::vector<double> newPlan=std::vector<double>(this->res,0);
    newPlan[leave]=Plan[leave]/div;
    for(int i=0; i<res; ++i)
    {
        if(i!=leave)
        newPlan[i]=(div*Plan[i]-A[i][come]*Plan[leave])/div;

    }
    this->A=newA;
    this->Plan=newPlan;
    Basis[leave]=come;
    CBasis[leave]=C[come];

}

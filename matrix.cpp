#include<iostream>
#include<stdlib.h>

using namespace std;



template <typename T> 
class matrix{
private:

public:
	
	T **value;
	int height=10;
	int width=10;
	
	
	
matrix(){
		value= new int*[height];
		
		for(int i=0;i<height;i++)
			value[i]=new int[width];
 	
		for(int i=0;i<height;i++)
			for(int j=0;j<width;j++)
			value[i][j]=0;
	}
	
	
matrix(int x,int y, int val){
		value= new int*[y];
		height=y;
		width=x;
		for(int i=0;i<y;i++)
			value[i]=new int[x];
		
		for(int i=0;i<y;i++)
			for(int j=0;j<x;j++)
			value[i][j]=val;
	}


	
matrix(int x,int y, char val){
		value= new int*[y];
		height=y;
		width=x;
		for(int i=0;i<y;i++)
			value[i]=new int[x];
		if(val=='r')
		for(int i=0;i<y;i++)
			for(int j=0;j<x;j++)
			value[i][j]=rand()%100;
			
		if(val=='e')
		for(int i=0;i<y;i++)
			for(int j=0;j<x;j++)
			if(i==j)
			value[i][j]=1;	
			else
				value[i][j]=0;	
	}
	
void resize(int x, int y){
		
		
	int tmpheight=height;
	int tmpwidth=width;
	width=x;
	height=y;
	
	
	
	int **tmp = new int*[height];
	
	for(int i=0;i<height;i++){
			tmp[i]=new int[width];
		
	}
	
	for(int i=0;i<height;i++){
				for(int j=0;j<width;j++){
				if(i<tmpwidth && j<tmpheight)
				tmp[i][j]=value[i][j];
				else
				tmp[i][j]=0;
			}
		}

		for(int i=0;i<tmpheight;i++)
	delete [] value[i];
	delete []value;
	
	 value = new int*[height];
	
	for(int i=0;i<height;i++){
			value[i]=new int[width];
		
	}
	
	for(int i=0;i<height;i++)
		for(int j=0;j<width;j++)
			value[i][j]=tmp[i][j];
			
				
	for(int i=0;i<height;i++)
	delete [] tmp[i];
	delete []tmp;
	
	
	}
	
void printMatrix(){
			for(int i=0;i<height;i++){
					for(int j=0;j<width;j++)
			cout<<value[i][j]<<" ";
			cout<<endl;
			}	
	}
	
		
matrix operator + (matrix &mt2){
		matrix m(width,height,0);
		if(this->height!=mt2.height && this->width!=mt2.width){
			cout<<"I think you have problem";
			return m;
		}
		
		m.width=mt2.width;
		m.height=mt2.height;
		for(int i=0;i<m.height;i++)
			for(int j=0;j<m.width;j++)
				m.value[i][j]=this->value[i][j] + mt2.value[i][j];
				
		return m;			
	}
	
matrix operator - (matrix &mt2){
		matrix m(width,height,0);
		if(this->height!=mt2.height && this->width!=mt2.width){
			cout<<"I think you have problem";
			return m;
		}
		
		m.width=mt2.width;
		m.height=mt2.height;
		for(int i=0;i<m.height;i++)
			for(int j=0;j<m.width;j++)
				m.value[i][j]=this->value[i][j] - mt2.value[i][j];
				
		return m;			
}
	
matrix operator * (matrix &mt2){
	
	matrix m(mt2.width,this->height,0);
	if(this->width==mt2.height){
		
	for(int i=0;i<this->height;i++)
		for(int j=0;j<mt2.width;j++)
			for(int k=0;k<this->width;k++)
				m.value[i][j]+=this->value[i][k]*mt2.value[k][j];

		return m;
			
	}else{
		cout<<"I think you have problem ";
		return m;
	}
	
	
			
}

void transpoz(){
		int **temp=new int*[height];
	
	for(int i=0;i<height;i++)
	temp[i]=new int[width];
	

	for(int i=0;i<height;i++)
	for(int j=0;j<width;j++)
		temp[j][i]=value[i][j];
		
		for(int i=0;i<height;i++)
	for(int j=0;j<width;j++)
		value[i][j]=temp[i][j];
		
		
	
}	
	
void emul (matrix &mt2){
	

	if(this->width==mt2.width && this->height==mt2.height){
		for(int i=0;i<height;i++)
		for(int j=0;j<width;j++)
			this->value[i][j]=this->value[i][j]*mt2.value[i][j];	
	}else{
		cout<<"I think you have problem ";
		
	}			
}



matrix operator + (int sayi){
	
		matrix m(width,height,0);
			m.width=width;
		    m.height=height;
		
		for(int i=0;i<m.height;i++)
			for(int j=0;j<m.width;j++)
				m.value[i][j]=value[i][j] +sayi;
				
		return m;			
}

matrix operator - (int sayi){
	
		matrix m(width,height,0);
			m.width=width;
		    m.height=height;
		
		for(int i=0;i<m.height;i++)
			for(int j=0;j<m.width;j++)
				m.value[i][j]=value[i][j] -sayi;
				
		return m;			
}
matrix operator * (int sayi){
	
		matrix m(width,height,0);
			m.width=width;
		    m.height=height;
		
		for(int i=0;i<m.height;i++)
			for(int j=0;j<m.width;j++)
				m.value[i][j]=value[i][j] *sayi;
				
		return m;			
}

matrix operator /(int sayi){
	
		matrix m(width,height,0);
			m.width=width;
		    m.height=height;
		
		for(int i=0;i<m.height;i++)
			for(int j=0;j<m.width;j++)
				m.value[i][j]=value[i][j] /sayi;
				
		return m;			
}
matrix operator ^ (int sayi){
	
		matrix m(width,height,0);
			m.width=width;
		    m.height=height;
		    for(int i=0;i<m.height;i++)
			for(int j=0;j<m.width;j++)
				m.value[i][j]=value[i][j];
				
				--sayi;
				
		for(int t=0;t<sayi;t++){
	
		for(int i=0;i<m.height;i++)
			for(int j=0;j<m.width;j++)
				m.value[i][j]*=value[i][j];
			}		
		return m;			
}
matrix operator % (int sayi){
	
		matrix m(width,height,0);
			m.width=width;
		    m.height=height;
		
		for(int i=0;i<m.height;i++)
			for(int j=0;j<m.width;j++)
				m.value[i][j]=value[i][j] %sayi;
				
		return m;		
}	
};




int main(){
	matrix<int> *m1=new matrix<int>(5,5,3);
	
	m1->printMatrix();
	

cout<<endl;


/*
	matrix<int> *m2=new matrix<int>(5,3,5);

	m2->printMatrix();
	cout<<endl<<endl;



m2->resize(15,15);
m2->printMatrix();
cout<<endl<<endl;
	
	
matrix<int> m3 = *m2 - *m1;
m3.printMatrix();
cout<<endl<<endl;






matrix<int> m4 = *m1 * *m2;
m4.printMatrix();
cout<<endl<<endl;
cout<<endl<<endl;

matrix<int> *m5 =new matrix<int>(5,5,'r');
m5->printMatrix();
m5->transpoz();
cout<<endl<<endl;
m5->printMatrix();
cout<<endl<<endl;

*/


matrix<int> *m4 = new matrix<int>(5,5,'e');

m4->printMatrix();
cout<<endl<<endl;
//matrix<int> m5=*m4^3;
*m4= *m4%5;
cout<<endl<<endl;
m4->printMatrix();




}

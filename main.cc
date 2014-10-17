#include <iostream>
#include <fstream>
#include <string>


using namespace std;
int main(int argc, char *argv[]){
	int pf,pl,k,n;//Respectively=>chosen point first and last,number of neigbours,number of points, 
	double xm,ym,xf,yf,xl,yl;//x and y coordinate of centered, chosen first and chosen last point,
	ifstream inFile (argv[1]);
	ofstream outfile (argv[2]);
	inFile>>n;//Taking the size
	inFile>>k;//Taking the number of points which need to be shown,
	
	double koor [n][2];//stores the coordinates
	int y=0;
	while(inFile>>koor[y][0]){
		inFile>>koor[y][1];
	    y++;
	}
	int sira[n][n+1];//stores the order
	//Gives basic values to the order
	for(int i=0;i<n ;i++){
		sira[i][0]=i+1;
	}
	for(int i=0;i<n ;i++){
		for(int j=0;j<n ;j++){
		sira[i][j+1]=j+1;
		}
	}
	//Puts the order in order
	for(int i=0;i<n;i++){
	xm=koor[i][0];
	ym=koor[i][1];
	for(int j=0;j<k+1 ;j++){
		for(int b=0;j+b<n-1;b++){
			pf=sira[i][n-b-1];
			pl=sira[i][n-b];
			xf=koor[pf-1][0];
			yf=koor[pf-1][1];
			xl=koor[pl-1][0];
			yl=koor[pl-1][1];
			if((xm-xf)*(xm-xf)+(ym-yf)*(ym-yf)>(xm-xl)*(xm-xl)+(ym-yl)*(ym-yl))//Changes the order
			{
				sira[i][n-b-1]=pl;
				sira[i][n-b]=pf;
			}
		}
	}
  }
  for(int h=0;h<n;h++){
	for(int l=0;l<k+1;l++){
		outfile<<sira[h][l+1]<<" ";	
	}
	   outfile<<endl;
	}
    return 0;
}


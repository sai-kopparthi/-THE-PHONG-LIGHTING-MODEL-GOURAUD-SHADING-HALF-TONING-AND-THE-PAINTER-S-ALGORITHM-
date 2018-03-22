

#ifdef WIN32
#include <windows.h>
#endif

#if defined (__APPLE__) || defined(MACOSX)
#include <OpenGL/gl.h>
//#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#else //linux
#include <GL/gl.h>
#include <GL/glut.h>
#endif

//other includes
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
//#include<algorithm>
float da[500][5000];
float e[500][5000];
float ga[500][5000];
int a,f[5000],b[5000],mid[5000],nmid;
int w[500][5000],q[500][5000],n[500][5000];
float kar[500],kag[500],kab[500],kdr[500],kdg[500],kdb[500],ksr[500],ksg[500],ksb[500];
int phexpo[500];
float xj,xk,lar,lag,lab,lir,lig,lib,fz,k;
float xa;
float x1,ya1,z1,x2,y2,z2;
//int npoly1;
float crspx[100][1000],crspy[100][1000],crspz[100][1000];
float nvx[100][1000],nvy[100][1000],nvz[100][100];
float nvx1[100][1000],nvy1[100][1000],nvz1[100][1000];
float count[100][1000];
float xa1,xj1,xk1;
float rx[100][1000],ry[100][1000],rz[100][1000];
float rx1[100][1000],ry1[100][1000],rz1[100][1000];
float vx[100][1000],vy[100][1000],vz[100][1000];
float vx1[100][1000],vy1[100][1000],vz1[100][1000];
int cz;
float fa,fb,fc;
float ix,iy,iz;
float iar[100][1000],iab[100][1000],iag[100][1000];
int lam;
int ar[100][5000];
float xmin1,ymin1,xmax1,ymax1,zmin1,zmax1;
float inter[20][200];//int c;
int ma;
float inter1[20][1000],inter2[20][1000];
int non,nor,nog,nob;
int c1,c2,c;
int apple;
int npoly1;
float ix1,iy1,iz1;
float intensity[100][1000][6];
float depthz[20][1000],depthza[1000];
int calz[20][1000],calza[1000];
int mn;int mn1;
float depthy[20][1000],depthx[20][1000];
int caly[20][1000],calx[20][1000];
//float inter1[20][100];
//the size of pixels sets the inital window height and width
//don't make the pixels too large or the screen size will be larger than
//your display size
FILE *fp = fopen("tobj.txt", "r+");
FILE *fp1 = fopen("materials.txt", "r+");
FILE *fp2 = fopen("light.txt", "r+");

/****set in main()****/
//the number of pixels in the grid
int grid_width;
int grid_height;

//the size of pixels sets the inital window height and width
//don't make the pixels too large or the screen size will be larger than
//your display size
float pixel_size;

/*Window information*/
int win_height;
int win_width;
int mass;
float max(float a,float b,float c)
{
if(a >=b && a>=c)
return a;
if(b >=a && b>=c)
return b;
if(c >=a && c>=b)
return c;
}
float abs1(float a)
{
if(a<0)
return -a;
else 
return a;
}
float abs2(float a)
{
if(a<0)
return 0;
else 
return a;
}
float dp(float x1,float y1,float z1,float x2,float y2,float z2)
{
float bo=((x1*x2)+(y1*y2)+(z1*z2));
return bo;
}

void init();
void idle();
void display();
void displaymas();
void displaymasxz();
void displaymasxy();
void draw_pix(int x, int y);
void draw_pix1(int x, int y);
void reshape(int width, int height);
void key(unsigned char ch, int x, int y);
void mouse(int button, int state, int x, int y);
void motion(int x, int y);
void check();

void phong()
{
for(int i=1;i<=a;i++)
	{
 	 for(int j=1;j<=f[i];j++)
		{
		float q=(xa-da[i][j]);
		float w=(xj-e[i][j]);
		float r=(xk-ga[i][j]);
		float m=q*q+w*w+r*r;
		float ta=sqrt(m);
		xa1=q/ta;
		xj1=w/ta;
		xk1=r/ta;
		float a=dp(nvx[i][j],nvy[i][j],nvz[i][j],q,w,r);
		rx[i][j]=((2*a*nvx[i][j])-(q));
		ry[i][j]=((2*a*nvy[i][j])-(w));
		rz[i][j]=((2*a*nvz[i][j])-(r));
		float x=(rx[i][j]*rx[i][j])+(ry[i][j]*ry[i][j])+(rz[i][j]*rz[i][j]);
		float sq=sqrt(x);
		rx1[i][j]=rx[i][j]/sq;
		ry1[i][j]=ry[i][j]/sq;
		rz1[i][j]=rz[i][j]/sq;
/*printf("%d \t %d \t",i,j);
printf("%f \t %f \t %f \n",(nvx[i][j]),(nvy[i][j]),(nvz[i][j]));*/
//printf("%f \n",a);
		float cosa=dp(nvx1[i][j],nvy1[i][j],nvz1[i][j],xa1,xj1,xk1);
		int cz=1;
		if(cz==1)
			{
			 fa=0.5;
			 fb=0.5;
			 fc=fz;			
			}
		else if(cz==2)
			{
			 fa=fz;
			 fb=0.5;
			 fc=0.5;			
			}
			else 
			{
			 fa=0.5;
			 fb=fz;
			 fc=0.5;			
			}
		vx[i][j]=(fa-da[i][j]);
		vy[i][j]=(fb-e[i][j]);
		vz[i][j]=(fc-ga[i][j]);
		float t=(vx[i][j]*vx[i][j])+(vy[i][j]*vy[i][j])+(vz[i][j]*vz[i][j]);
		float ep=sqrt(t);
		vx1[i][j]=vx[i][j]/ep;
		vy1[i][j]=vy[i][j]/ep;
		vz1[i][j]=vz[i][j]/ep;
		float cosb=dp(rx1[i][j],ry1[i][j],rz1[i][j],vx1[i][j],vy1[i][j],vz1[i][j]);
//printf();
		
		float mb,ma;
		mb=sqrt(((fa-(da[i][j]))*(fa-(da[i][j])))+((fb-(e[i][j]))*(fb-(e[i][j])))+((fc-(ga[i][j]))*(fc-(ga[i][j]))));
		ma=abs1(mb);
	//printf("%d %d \t",i,j);
			iar[i][j]=(kar[lam]*lar)+((lir/(ma+k))*(kdr[lam]*cosa))+((lir/(ma+k))*(ksr[lam]*pow(cosb,phexpo[lam])));
			//printf("%f \t",iar[i][j]);
			iab[i][j]=(kab[lam]*lab)+((lib/(ma+k))*(kdb[lam]*cosa))+((lib/(ma+k))*(ksb[lam]*pow(cosb,phexpo[lam])));
				//printf("%f \t",iab[i][j]);
			iag[i][j]=(kag[lam]*lag)+((lig/(ma+k))*(kdg[lam]*cosa))+((lig/(ma+k))*(ksg[lam]*pow(cosb,phexpo[lam])));
	
		}
		 		

  	}
}
void lineDDA1(float x0, float y0, float xE, float yE)
{
float dx = xE - x0, dy = yE - y0, steps, k;
float xI, yI, x = x0, y = y0;
if (fabs (dx) > fabs (dy))
steps = fabs (dx);
else
steps = fabs (dy);
xI = float (dx) / float (steps);
yI = float (dy) / float (steps);
draw_pix(round (x), round (y));
for (k = 0; k < steps; k++) {
x += xI;
y += yI;
 draw_pix(round (x), round (y));
}
}

void lineDDA (float x0, float y0, float xE, float yE,int npoly1,int vertex1,int vertex2)
{
float dx = xE - x0, dy = yE - y0, steps, k;
float xI, yI, x = x0, y = y0;
if (fabs (dx) > fabs (dy))
steps = fabs (dx);
else
steps = fabs (dy);
xI = float (dx) / float (steps);
yI = float (dy) / float (steps);
draw_pix(round (x), round (y));
for (k = 0; k < steps; k++) {
x += xI;
y += yI;
float dis1=sqrt((( (x)-x0)*( (x)-x0))+(( (y)-y0)*( (y)-y0)));
float dis2=sqrt((( (x)-xE)*( (x)-xE))+(( (y)-yE)*( (y)-yE)));
float dis3=sqrt(((xE-x0)*(xE-x0))+((yE-y0)*(yE-y0)));
float alp1=dis1/dis3;
float alp2=dis2/dis3;
float a1=alp2*abs2(iar[npoly1][vertex1]);
float b1=alp2*abs2(iag[npoly1][vertex1]);
float c1=alp2*abs2(iab[npoly1][vertex1]);
float a2=alp1*abs2(iar[npoly1][vertex2]);
float b2=alp1*abs2(iag[npoly1][vertex2]);
float c2=alp1*abs2(iab[npoly1][vertex2]);
ix=a1+a2;
iy=b1+b2;
iz=c1+c2;
if(apple==1)
 draw_pix(round (x), round (y));
else
draw_pix1(round (x), round (y));;
}
}
void lineDDA3 (float x0, float y0, float xE, float yE)
{
float dx = xE - x0, dy = yE - y0, steps, k;
float xI, yI, x = x0, y = y0;
if (fabs (dx) > fabs (dy))
steps = fabs (dx);
else
steps = fabs (dy);
xI = float (dx) / float (steps);
yI = float (dy) / float (steps);
draw_pix(round (x), round (y));
for (k = 0; k < steps; k++) {
x += xI;
y += yI;
float dis1=sqrt((( (x)-x0)*( (x)-x0))+(( (y)-y0)*( (y)-y0)));
float dis2=sqrt((( (x)-xE)*( (x)-xE))+(( (y)-yE)*( (y)-yE)));
float dis3=sqrt(((xE-x0)*(xE-x0))+((yE-y0)*(yE-y0)));
float alp1=dis1/dis3;
float alp2=dis2/dis3;
float a1=alp2*intensity[npoly1][c][1];
float b1=alp2*intensity[npoly1][c][2];
float c1=alp2*intensity[npoly1][c][3];
float a2=alp1*intensity[npoly1][c+1][1];
float b2=alp1*intensity[npoly1][c+1][2];
float c2=alp1*intensity[npoly1][c+1][3];
ix=a1+a2;
iy=b1+b2;
iz=c1+c2;
if(apple==1)
 draw_pix(round (x), round (y));
else
draw_pix1(round (x), round (y));;
}
}
void draw_pix(int x, int y){
    glBegin(GL_POINTS);
    glColor3f(ix,iy,iz);
    glVertex3f(x+.5,y+.5,0);
    glEnd();
}
void draw_pix1(int x, int y){
float r[10],g[10],b[10];
 non=round(9*max(ix,iy,iz));
 nor=round((ix/(ix+iy+iz))*non);
 nog=round((iy/(ix+iy+iz))*non);
 nob=round((iz/(ix+iy+iz))*non);
//printf("non %d \t nor  %d  \t nog %d  \tnob %d  \t",non,nor,nog,nob);

for(int i=1;i<=nor;i++)
{
r[i]=1.0;
}
for(int i=1;i<=nob;i++)
{
b[i]=1.0;
}
for(int i=1;i<=nog;i++)
{
g[i]=1.0;
}
    glBegin(GL_POINTS);
    glColor3f(r[3],g[9],b[9]);
    glVertex3f(x+.1,y+.1,0);
glColor3f(r[6],g[8],b[7]);
    glVertex3f(x+0.2,y+.1,0);
glColor3f(r[9],g[7],b[5]);
    glVertex3f(x+0.3,y+.1,0);
glColor3f(r[1],g[6],b[3]);
    glVertex3f(x+.1,y+0.2,0);
glColor3f(r[4],g[5],b[1]);
    glVertex3f(x+.2,y+.2,0);
glColor3f(r[7],g[1],b[8]);
    glVertex3f(x+.3,y+.2,0);
glColor3f(r[2],g[2],b[6]);
    glVertex3f(x+0.1,y+0.3,0);
glColor3f(r[5],g[3],b[4]);
    glVertex3f(x+0.2,y+.3,0);
glColor3f(r[8],g[4],b[2]);
    glVertex3f(x+0.3,y+.3,0);

    glEnd();
}
float min1(int i,int j)
{
float z1=ga[i][q[i][j]];
float z2=ga[i][w[i][j]];
float z3=ga[i][n[i][j]];
if(z1<z2 && z1<z3)
return z1;
else if(z2<z1 && z2<z3)
return z2;
else if(z3<z1 && z3<z1)
return z3;
}
void painterxy()
{
for(int i=1;i<=a;i++)
{
for(int j=1;j<=b[i];j++)
{
  	depthz[i][j]=min1(i,j);
}
}
}
/*void dispainxy()
{
for(int i=1;i<=a;i++)
{
for(int j=1;j<=b[i];j++)
{
 printf("i %d j %d %f \n ",i,j,depthz[i][j]);
}
}
}*/
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 void swap1(float *xp, float *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}
// A function to implement bubble sort
void bubbleSortz()
{
   int i, j,k,na;
for(k=1;k<=a;k++)
{
	na=b[k];
   for (i = 1; i <= na-1; i++)      
     // Last i elements are already in place   
       for (j = 1; j < na-i-1; j++) 
           if (depthz[k][j] < depthz[k][j+1])
	    {	
              swap1(&depthz[k][j], &depthz[k][j+1]);
	      swap(&calz[k][j],&calz[k][j+1]);
	    }
}
}
void intializez()
{
for(int i=1;i<=a;i++)
{
for(int j=1;j<=b[i];j++)
{
calz[i][j]=j;
}
}
} 
/* Function to print an array */
void printArray(){
    int i;
    for(int i=1;i<=a;i++)
	{
	for(int j=1;j<=b[i];j++)
	{
        printf("%d \n",calz[i][j]);

}
}
}
void narray()
{
mn=1;
for(int i=1;i<=a;i++)
{


for(int j=mn;j<=mn+b[i];j++)
{

depthza[j]=depthz[i][j];
calza[j]=calz[i][j];
mn=mn+b[i];
}
}

}
void incrment()
{
for(int i=1;i<=a;i++)
{
mn=mn+b[i];
}
}
void prints()
{
for(int j=1;j<=mn;j++)
{
printf("triangle %d \n",calza[j]);
}
}
float min2(int i,int j)
{
float y1=e[i][q[i][j]];
float y2=e[i][w[i][j]];
float y3=e[i][n[i][j]];
if(y1<y2 && y1<y3)
return y1;
else if(y2<y1 && y2<y3)
return y2;
else if(y3<y1 && y3<y1)
return y3;
}
void painterxz()
{
for(int i=1;i<=a;i++)
{
for(int j=1;j<=b[i];j++)
{
  	depthy[i][j]=min2(i,j);
}
}
}
/*void dispainxy()
{
for(int i=1;i<=a;i++)
{
for(int j=1;j<=b[i];j++)
{
 printf("i %d j %d %f \n ",i,j,depthz[i][j]);
}
}
}*/

// A function to implement bubble sort
void bubbleSorty()
{
   int i, j,k,na;
for(k=1;k<=a;k++)
{
	na=b[k];
   for (i = 1; i <= na-1; i++)      
     // Last i elements are already in place   
       for (j = 1; j < na-i-1; j++) 
           if (depthy[k][j] < depthy[k][j+1])
	    {	
              swap1(&depthy[k][j], &depthy[k][j+1]);
	      swap(&caly[k][j],&caly[k][j+1]);
	    }
}
}
void intializey()
{
for(int i=1;i<=a;i++)
{
for(int j=1;j<=b[i];j++)
{
caly[i][j]=j;
}
}
} 
void dispainxz()
{
for(int i=1;i<=a;i++)
{
for(int j=1;j<=b[i];j++)
{
 printf("i %d j %d %f \n ",i,j,depthy[i][j]);
}
}
}
void printArrayy(){
    int i;
    for(int i=1;i<=a;i++)
	{
	for(int j=1;j<=b[i];j++)
	{
        printf("%d \n",caly[i][j]);

}
}
}

float min3(int i,int j)
{
float y1=da[i][q[i][j]];
float y2=da[i][w[i][j]];
float y3=da[i][n[i][j]];
if(y1<y2 && y1<y3)
return y1;
else if(y2<y1 && y2<y3)
return y2;
else if(y3<y1 && y3<y1)
return y3;
}
void painteryz()
{
for(int i=1;i<=a;i++)
{
for(int j=1;j<=b[i];j++)
{
  	depthx[i][j]=min3(i,j);
}
}
}
/*void dispainxy()
{
for(int i=1;i<=a;i++)
{
for(int j=1;j<=b[i];j++)
{
 printf("i %d j %d %f \n ",i,j,depthz[i][j]);
}
}
}*/

// A function to implement bubble sort
void bubbleSortx()
{
   int i, j,k,na;
for(k=1;k<=a;k++)
{
	na=b[k];
   for (i = 1; i <= na-1; i++)      
     // Last i elements are already in place   
       for (j = 1; j < na-i-1; j++) 
           if (depthx[k][j] < depthx[k][j+1])
	    {	
              swap1(&depthx[k][j], &depthx[k][j+1]);
	      swap(&calx[k][j],&calx[k][j+1]);
	    }
}
}
void intializex()
{
for(int i=1;i<=a;i++)
{
for(int j=1;j<=b[i];j++)
{
calx[i][j]=j;
}
}
} 
void dispainyz()
{
for(int i=1;i<=a;i++)
{
for(int j=1;j<=b[i];j++)
{
 printf("i %d j %d %f \n ",i,j,depthx[i][j]);
}
}
}
void printArrayx(){
    int i;
    for(int i=1;i<=a;i++)
	{
	for(int j=1;j<=b[i];j++)
	{
        printf("%d \n",calx[i][j]);

}
}
}
void drawpolyxy()
{
for(int i=1;i<=a;i++)
	{
	for(int j=1;j<=b[i];j++)
		{
			lineDDA((da[i][q[i][calz[i][j]]]*100),(e[i][q[i][calz[i][j]]]*100),(da[i][w[i][calz[i][j]]]*100),(e[i][w[i][calz[i][j]]]*100),i,q[i][calz[i][j]],w[i][calz[i][j]]);
			lineDDA((da[i][w[i][calz[i][j]]]*100),(e[i][w[i][calz[i][j]]]*100),(da[i][n[i][calz[i][j]]]*100),(e[i][n[i][calz[i][j]]]*100),i,w[i][calz[i][j]],n[i][calz[i][j]]);
			lineDDA((da[i][n[i][calz[i][j]]]*100),(e[i][n[i][calz[i][j]]]*100),(da[i][q[i][calz[i][j]]]*100),(e[i][q[i][calz[i][j]]]*100),i,n[i][calz[i][j]],q[i][calz[i][j]]);
		  }
}


}
void drawpolyxz()
{
for(int i=1;i<=a;i++)
	{
	for(int j=1;j<=b[i];j++)
		{
			lineDDA((da[i][q[i][caly[i][j]]]*100),(ga[i][q[i][caly[i][j]]]*100),(da[i][w[i][caly[i][j]]]*100),(ga[i][w[i][caly[i][j]]]*100),i,q[i][caly[i][j]],w[i][caly[i][j]]);
			lineDDA((da[i][w[i][caly[i][j]]]*100),(ga[i][w[i][caly[i][j]]]*100),(da[i][n[i][caly[i][j]]]*100),(ga[i][n[i][caly[i][j]]]*100),i,w[i][caly[i][j]],n[i][caly[i][j]]);
			lineDDA((da[i][n[i][caly[i][j]]]*100),(ga[i][n[i][caly[i][j]]]*100),(da[i][q[i][caly[i][j]]]*100),(ga[i][q[i][caly[i][j]]]*100),i,n[i][caly[i][j]],q[i][caly[i][j]]);
		  }
}
}
void drawpolyyz()
{
for(int i=1;i<=a;i++)
	
	{
	for(int j=1;j<=b[i];j++)
		{
			lineDDA((e[i][q[i][calx[i][j]]]*100),(ga[i][q[i][calx[i][j]]]*100),(e[i][w[i][calx[i][j]]]*100),(ga[i][w[i][calx[i][j]]]*100),i,q[i][calx[i][j]],w[i][calx[i][j]]);
			lineDDA((e[i][w[i][calx[i][j]]]*100),(ga[i][w[i][calx[i][j]]]*100),(e[i][n[i][calx[i][j]]]*100),(ga[i][n[i][calx[i][j]]]*100),i,w[i][calx[i][j]],n[i][calx[i][j]]);
			lineDDA((e[i][n[i][calx[i][j]]]*100),(ga[i][n[i][calx[i][j]]]*100),(e[i][q[i][calx[i][j]]]*100),(ga[i][q[i][calx[i][j]]]*100),i,n[i][calx[i][j]],q[i][calx[i][j]]);
		  }
	}
}


void calcsxmin()
{ //MAX,MIN
    
        if(xmin1>da[npoly1][q[npoly1][ma]])
        xmin1=da[npoly1][q[npoly1][ma]];
	else if(xmin1>da[npoly1][w[npoly1][ma]])
	xmin1=da[npoly1][w[npoly1][ma]];
	else if(xmin1>da[npoly1][n[npoly1][ma]]) 
	xmin1=da[npoly1][n[npoly1][ma]];
          }
void calcsxmax()
{
	if(xmax1<da[npoly1][q[npoly1][ma]])
        xmax1=da[npoly1][q[npoly1][ma]];
	else if(xmin1<da[npoly1][w[npoly1][ma]])
	xmax1=da[npoly1][w[npoly1][ma]];
	else if(xmax1<da[npoly1][n[npoly1][ma]])
	xmax1=da[npoly1][n[npoly1][ma]];
}
void calcsymax()
{
	if(ymax1<e[npoly1][q[npoly1][ma]])
        ymax1=e[npoly1][q[npoly1][ma]];
	else if(ymax1<e[npoly1][w[npoly1][ma]])
	ymax1=e[npoly1][w[npoly1][ma]];
	else if(ymax1<e[npoly1][n[npoly1][ma]])
	ymax1=e[npoly1][n[npoly1][ma]];
}
void calcsymin()
{ //MAX,MIN
    
        if(ymin1>e[npoly1][q[npoly1][ma]])
        ymin1=e[npoly1][q[npoly1][ma]];
	else if(ymin1>e[npoly1][w[npoly1][ma]])
	ymin1=e[npoly1][w[npoly1][ma]];
	else if(ymin1>e[npoly1][n[npoly1][ma]])
	ymin1=e[npoly1][n[npoly1][ma]];
          }

void calcszmax()
{
	if(zmax1<ga[npoly1][q[npoly1][ma]])
        zmax1=ga[npoly1][q[npoly1][ma]];
	else if(zmax1<ga[npoly1][w[npoly1][ma]])
	zmax1=ga[npoly1][w[npoly1][ma]];
	else if(zmax1<ga[npoly1][n[npoly1][ma]])
	zmax1=ga[npoly1][n[npoly1][ma]];
}
void calcszmin()
{ //MAX,MIN
    
        if(zmin1>ga[npoly1][q[npoly1][ma]])
        zmin1=ga[npoly1][q[npoly1][ma]];
	else if(zmin1>ga[npoly1][w[npoly1][ma]])
	zmin1=ga[npoly1][w[npoly1][ma]];
	else if(zmin1>e[npoly1][n[npoly1][ma]])
	zmin1=ga[npoly1][n[npoly1][ma]];
          }
void intsb(float z) //DEFINE FUNCTION INTS
{



    float x1,x2,y1,y2,temp,x;
    
    c=0;
	x1=e[npoly1][q[npoly1][ma]];
        y1=ga[npoly1][q[npoly1][ma]];
        x2=e[npoly1][w[npoly1][ma]];
        y2=ga[npoly1][w[npoly1][ma]];

        if(y2<y1)
        {
            temp=x1;
            x1=x2;
            x2=temp;
            temp=y1;
            y1=y2;
            y2=temp;
        }
        if(z<=y2&&z>=y1)
        {
            if((y1-y2)==0)
            x=x1;
            else // used to make changes in x. so that we can fill our polygon after cerain distance
            {
                x=((x2-x1)*(z-y1))/(y2-y1);
                x=x+x1;
	
            }
            if(x<=ymax1 && x>=ymin1)
	{
            c=c+1;
float dis1=sqrt(((x-x1)*(x-x1))+((z-y1)*(z-y1)));
float dis2=sqrt(((x-x2)*(x-x2))+((z-y2)*(z-y2)));
float dis3=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
float alp1=dis1/dis3;
float alp2=dis2/dis3;
float a1=alp2*abs2(iar[npoly1][q[npoly1][ma]]);
float b1=alp2*abs2(iag[npoly1][q[npoly1][ma]]);
float c1=alp2*abs2(iab[npoly1][q[npoly1][ma]]);
float a2=alp1*abs2(iar[npoly1][w[npoly1][ma]]);
float b2=alp1*abs2(iag[npoly1][w[npoly1][ma]]);
float c2=alp1*abs2(iab[npoly1][w[npoly1][ma]]);
ix1=a1+a2;
iy1=b1+b2;
iz1=c1+c2;
		intensity[npoly1][c][1]=ix1;
		intensity[npoly1][c][2]=iy1;
		intensity[npoly1][c][3]=iz1;
		
            inter1[npoly1][c]=x;
		
 
	}     
   
    }

x1=e[npoly1][w[npoly1][ma]];
        y1=ga[npoly1][w[npoly1][ma]];
        x2=e[npoly1][n[npoly1][ma]];
        y2=ga[npoly1][n[npoly1][ma]];

        if(y2<y1)
        {
            temp=x1;
            x1=x2;
            x2=temp;
            temp=y1;
            y1=y2;
            y2=temp;
        }
        if(z<=y2&&z>=y1)
        {
            if((y1-y2)==0)
            x=x1;
            else // used to make changes in x. so that we can fill our polygon after cerain distance
            {
                x=((x2-x1)*(z-y1))/(y2-y1);
                x=x+x1;
	
            }
            if(x<=ymax1 && x>=ymin1)
	{
            c=c+1;
				float dis1=sqrt(((x-x1)*(x-x1))+((z-y1)*(z-y1)));
float dis2=sqrt(((x-x2)*(x-x2))+((z-y2)*(z-y2)));
float dis3=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
float alp1=dis1/dis3;
float alp2=dis2/dis3;
float a1=alp2*abs2(iar[npoly1][w[npoly1][ma]]);
float b1=alp2*abs2(iag[npoly1][w[npoly1][ma]]);
float c1=alp2*abs2(iab[npoly1][w[npoly1][ma]]);
float a2=alp1*abs2(iar[npoly1][n[npoly1][ma]]);
float b2=alp1*abs2(iag[npoly1][n[npoly1][ma]]);
float c2=alp1*abs2(iab[npoly1][n[npoly1][ma]]);
ix1=a1+a2;
iy1=b1+b2;
iz1=c1+c2;
		intensity[npoly1][c][1]=ix1;
		intensity[npoly1][c][2]=iy1;
		intensity[npoly1][c][3]=iz1;
            inter1[npoly1][c]=x;
		
 
	}     
   
    }
x1=e[npoly1][n[npoly1][ma]];
        y1=ga[npoly1][n[npoly1][ma]];
        x2=e[npoly1][q[npoly1][ma]];
        y2=ga[npoly1][q[npoly1][ma]];

        if(y2<y1)
        {
            temp=x1;
            x1=x2;
            x2=temp;
            temp=y1;
            y1=y2;
            y2=temp;
        }
        if(z<=y2&&z>=y1)
        {
            if((y1-y2)==0)
            x=x1;
            else // used to make changes in x. so that we can fill our polygon after cerain distance
            {
                x=((x2-x1)*(z-y1))/(y2-y1);
                x=x+x1;
	
            }
            if(x<=zmax1 && x>=zmin1)
	{
            c=c+1;
		float dis1=sqrt(((x-x1)*(x-x1))+((z-y1)*(z-y1)));
float dis2=sqrt(((x-x2)*(x-x2))+((z-y2)*(z-y2)));
float dis3=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
float alp1=dis1/dis3;
float alp2=dis2/dis3;
float a1=alp2*abs2(iar[npoly1][n[npoly1][ma]]);
float b1=alp2*abs2(iag[npoly1][n[npoly1][ma]]);
float c1=alp2*abs2(iab[npoly1][n[npoly1][ma]]);
float a2=alp1*abs2(iar[npoly1][q[npoly1][ma]]);
float b2=alp1*abs2(iag[npoly1][q[npoly1][ma]]);
float c2=alp1*abs2(iab[npoly1][q[npoly1][ma]]);
ix1=a1+a2;
iy1=b1+b2;
iz1=c1+c2;
		intensity[npoly1][c][1]=ix1;
		intensity[npoly1][c][2]=iy1;
		intensity[npoly1][c][3]=iz1;
		
            inter1[npoly1][c]=x;
		
 
	}     
   
    }



}
void intsa(float z) //DEFINE FUNCTION INTS
{



    float x1,x2,y1,y2,temp,x;
    
    c=0;
	x1=da[npoly1][q[npoly1][ma]];
        y1=e[npoly1][q[npoly1][ma]];
        x2=da[npoly1][w[npoly1][ma]];
        y2=e[npoly1][w[npoly1][ma]];

        if(y2<y1)
        {
            temp=x1;
            x1=x2;
            x2=temp;
            temp=y1;
            y1=y2;
            y2=temp;
        }
        if(z<=y2&&z>=y1)
        {
            if((y1-y2)==0)
            x=x1;
            else // used to make changes in x. so that we can fill our polygon after cerain distance
            {
                x=((x2-x1)*(z-y1))/(y2-y1);
                x=x+x1;
	
            }
            if(x<=xmax1 && x>=xmin1)
	{
            c=c+1;
		float dis1=sqrt(((x-x1)*(x-x1))+((z-y1)*(z-y1)));
float dis2=sqrt(((x-x2)*(x-x2))+((z-y2)*(z-y2)));
float dis3=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
float alp1=dis1/dis3;
float alp2=dis2/dis3;
float a1=alp2*abs2(iar[npoly1][q[npoly1][ma]]);
float b1=alp2*abs2(iag[npoly1][q[npoly1][ma]]);
float c1=alp2*abs2(iab[npoly1][q[npoly1][ma]]);
float a2=alp1*abs2(iar[npoly1][w[npoly1][ma]]);
float b2=alp1*abs2(iag[npoly1][w[npoly1][ma]]);
float c2=alp1*abs2(iab[npoly1][w[npoly1][ma]]);
ix1=a1+a2;
iy1=b1+b2;
iz1=c1+c2;
		intensity[npoly1][c][1]=ix1;
		intensity[npoly1][c][2]=iy1;
		intensity[npoly1][c][3]=iz1;
            inter[npoly1][c]=x;
		
 
	}     
   
    }

x1=da[npoly1][w[npoly1][ma]];
        y1=e[npoly1][w[npoly1][ma]];
        x2=da[npoly1][n[npoly1][ma]];
        y2=e[npoly1][n[npoly1][ma]];

        if(y2<y1)
        {
            temp=x1;
            x1=x2;
            x2=temp;
            temp=y1;
            y1=y2;
            y2=temp;
        }
        if(z<=y2&&z>=y1)
        {
            if((y1-y2)==0)
            x=x1;
            else // used to make changes in x. so that we can fill our polygon after cerain distance
            {
                x=((x2-x1)*(z-y1))/(y2-y1);
                x=x+x1;
	
            }
            if(x<=xmax1 && x>=xmin1)
	{
            c=c+1;
		float dis1=sqrt(((x-x1)*(x-x1))+((z-y1)*(z-y1)));
float dis2=sqrt(((x-x2)*(x-x2))+((z-y2)*(z-y2)));
float dis3=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
float alp1=dis1/dis3;
float alp2=dis2/dis3;
float a1=alp2*abs2(iar[npoly1][w[npoly1][ma]]);
float b1=alp2*abs2(iag[npoly1][w[npoly1][ma]]);
float c1=alp2*abs2(iab[npoly1][w[npoly1][ma]]);
float a2=alp1*abs2(iar[npoly1][n[npoly1][ma]]);
float b2=alp1*abs2(iag[npoly1][n[npoly1][ma]]);
float c2=alp1*abs2(iab[npoly1][n[npoly1][ma]]);
ix1=a1+a2;
iy1=b1+b2;
iz1=c1+c2;
		intensity[npoly1][c][1]=ix1;
		intensity[npoly1][c][2]=iy1;
		intensity[npoly1][c][3]=iz1;
            inter[npoly1][c]=x;
		
 
	}     
   
    }
x1=da[npoly1][n[npoly1][ma]];
        y1=e[npoly1][n[npoly1][ma]];
        x2=da[npoly1][q[npoly1][ma]];
        y2=e[npoly1][q[npoly1][ma]];

        if(y2<y1)
        {
            temp=x1;
            x1=x2;
            x2=temp;
            temp=y1;
            y1=y2;
            y2=temp;
        }
        if(z<=y2&&z>=y1)
        {
            if((y1-y2)==0)
            x=x1;
            else // used to make changes in x. so that we can fill our polygon after cerain distance
            {
                x=((x2-x1)*(z-y1))/(y2-y1);
                x=x+x1;
	
            }
            if(x<=xmax1 && x>=xmin1)
	{
            c=c+1;
		float dis1=sqrt(((x-x1)*(x-x1))+((z-y1)*(z-y1)));
float dis2=sqrt(((x-x2)*(x-x2))+((z-y2)*(z-y2)));
float dis3=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
float alp1=dis1/dis3;
float alp2=dis2/dis3;
float a1=alp2*abs2(iar[npoly1][n[npoly1][ma]]);
float b1=alp2*abs2(iag[npoly1][n[npoly1][ma]]);
float c1=alp2*abs2(iab[npoly1][n[npoly1][ma]]);
float a2=alp1*abs2(iar[npoly1][q[npoly1][ma]]);
float b2=alp1*abs2(iag[npoly1][q[npoly1][ma]]);
float c2=alp1*abs2(iab[npoly1][q[npoly1][ma]]);
ix1=a1+a2;
iy1=b1+b2;
iz1=c1+c2;
		intensity[npoly1][c][1]=ix1;
		intensity[npoly1][c][2]=iy1;
		intensity[npoly1][c][3]=iz1;
		
            inter[npoly1][c]=x;
		
 
	}     
   
    }



}

  void ints(float z) //DEFINE FUNCTION INTS
{



    float x1,x2,y1,y2,temp,x;
    
    c=0;
	x1=da[npoly1][q[npoly1][ma]];
        y1=ga[npoly1][q[npoly1][ma]];
        x2=da[npoly1][w[npoly1][ma]];
        y2=ga[npoly1][w[npoly1][ma]];

        if(y2<y1)
        {
            temp=x1;
            x1=x2;
            x2=temp;
            temp=y1;
            y1=y2;
            y2=temp;
        }
        if(z<=y2&&z>=y1)
        {
            if((y1-y2)==0)
            x=x1;
            else // used to make changes in x. so that we can fill our polygon after cerain distance
            {
                x=((x2-x1)*(z-y1))/(y2-y1);
                x=x+x1;
	
            }
            if(x<=xmax1 && x>=xmin1)
	{
            c=c+1;
		float dis1=sqrt(((x-x1)*(x-x1))+((z-y1)*(z-y1)));
float dis2=sqrt(((x-x2)*(x-x2))+((z-y2)*(z-y2)));
float dis3=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
float alp1=dis1/dis3;
float alp2=dis2/dis3;
float a1=alp2*abs2(iar[npoly1][q[npoly1][ma]]);
float b1=alp2*abs2(iag[npoly1][q[npoly1][ma]]);
float c1=alp2*abs2(iab[npoly1][q[npoly1][ma]]);
float a2=alp1*abs2(iar[npoly1][w[npoly1][ma]]);
float b2=alp1*abs2(iag[npoly1][w[npoly1][ma]]);
float c2=alp1*abs2(iab[npoly1][w[npoly1][ma]]);
ix1=a1+a2;
iy1=b1+b2;
iz1=c1+c2;
		intensity[npoly1][c][1]=ix1;
		intensity[npoly1][c][2]=iy1;
		intensity[npoly1][c][3]=iz1;
            inter[npoly1][c]=x;
		
 
	}     
   
    }

x1=da[npoly1][w[npoly1][ma]];
        y1=ga[npoly1][w[npoly1][ma]];
        x2=da[npoly1][n[npoly1][ma]];
        y2=ga[npoly1][n[npoly1][ma]];

        if(y2<y1)
        {
            temp=x1;
            x1=x2;
            x2=temp;
            temp=y1;
            y1=y2;
            y2=temp;
        }
        if(z<=y2&&z>=y1)
        {
            if((y1-y2)==0)
            x=x1;
            else // used to make changes in x. so that we can fill our polygon after cerain distance
            {
                x=((x2-x1)*(z-y1))/(y2-y1);
                x=x+x1;
	
            }
            if(x<=xmax1 && x>=xmin1)
	{
            c=c+1;
		float dis1=sqrt(((x-x1)*(x-x1))+((z-y1)*(z-y1)));
float dis2=sqrt(((x-x2)*(x-x2))+((z-y2)*(z-y2)));
float dis3=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
float alp1=dis1/dis3;
float alp2=dis2/dis3;
float a1=alp2*abs2(iar[npoly1][w[npoly1][ma]]);
float b1=alp2*abs2(iag[npoly1][w[npoly1][ma]]);
float c1=alp2*abs2(iab[npoly1][w[npoly1][ma]]);
float a2=alp1*abs2(iar[npoly1][n[npoly1][ma]]);
float b2=alp1*abs2(iag[npoly1][n[npoly1][ma]]);
float c2=alp1*abs2(iab[npoly1][n[npoly1][ma]]);
ix1=a1+a2;
iy1=b1+b2;
iz1=c1+c2;
		intensity[npoly1][c][1]=ix1;
		intensity[npoly1][c][2]=iy1;
		intensity[npoly1][c][3]=iz1;
            inter[npoly1][c]=x;
		
 
	}     
   
    }
x1=da[npoly1][n[npoly1][ma]];
        y1=ga[npoly1][n[npoly1][ma]];
        x2=da[npoly1][q[npoly1][ma]];
        y2=ga[npoly1][q[npoly1][ma]];

        if(y2<y1)
        {
            temp=x1;
            x1=x2;
            x2=temp;
            temp=y1;
            y1=y2;
            y2=temp;
        }
        if(z<=y2&&z>=y1)
        {
            if((y1-y2)==0)
            x=x1;
            else // used to make changes in x. so that we can fill our polygon after cerain distance
            {
                x=((x2-x1)*(z-y1))/(y2-y1);
                x=x+x1;
	
            }
            if(x<=xmax1 && x>=xmin1)
	{   
		
            c=c+1;
float dis1=sqrt(((x-x1)*(x-x1))+((z-y1)*(z-y1)));
float dis2=sqrt(((x-x2)*(x-x2))+((z-y2)*(z-y2)));
float dis3=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
float alp1=dis1/dis3;
float alp2=dis2/dis3;
float a1=alp2*abs2(iar[npoly1][n[npoly1][ma]]);
float b1=alp2*abs2(iag[npoly1][n[npoly1][ma]]);
float c1=alp2*abs2(iab[npoly1][n[npoly1][ma]]);
float a2=alp1*abs2(iar[npoly1][q[npoly1][ma]]);
float b2=alp1*abs2(iag[npoly1][q[npoly1][ma]]);
float c2=alp1*abs2(iab[npoly1][q[npoly1][ma]]);
ix1=a1+a2;
iy1=b1+b2;
iz1=c1+c2;
		intensity[npoly1][c][1]=ix1;
		intensity[npoly1][c][2]=iy1;
		intensity[npoly1][c][3]=iz1;
		
            inter[npoly1][c]=x;
		
 
	}     
   
    }



}

int main(int argc, char **argv)
{
    
    //the number of pixels in the grid
    grid_width = 100;
    grid_height = 100;

    //the size of pixels sets the inital window height and width
    //don't make the pixels too large or the screen size will be larger than
    //your display size
    pixel_size = 5.0;
   // ymin1=xmin1=xmax1=ymax1=0;
    /*Window information*/
    win_height = grid_height*pixel_size;
    win_width = grid_width*pixel_size;
    GLint nump;
	fscanf(fp,"%d",&nump);
	a=nump;

for(int i=1;i<=a;i++)
	{
	//printf("Enter the number of vertices in a %d polygon\n",i+1);
	GLint ab;
	fscanf(fp,"%d",&ab);
	mid[i]=ab;
	GLint vertex;
	fscanf(fp,"%d",&vertex);
	f[i]=vertex;
	//scanf("%d",&v[i]);
 GLfloat ycord;
		GLfloat xcord;
		GLfloat zcord;
	  for(int j=1;j<=f[i];j++)
	{
	    // printf("Enter the %d point x and y coordinate respectively\n",j+1);
	   
	     fscanf(fp,"%f",&xcord);
		  da[i][j]=xcord;
	     fscanf(fp,"%f",&ycord);
		  e[i][j]=ycord;	
	     fscanf(fp,"%f",&zcord);
	          ga[i][j]=zcord;
	    //printf("%f",d[i][j]);
	
	}
		GLint tri;
		fscanf(fp,"%d",&tri);
	b[i]=tri;
           for(int j=1;j<=b[i];j++)
	{
	GLfloat qedge,wedge,fedge;
	     fscanf(fp,"%f",&qedge);
	     fscanf(fp,"%f",&wedge);
	     fscanf(fp,"%f",&fedge);
	q[i][j]=qedge;
	w[i][j]=wedge;
	n[i][j]=fedge;	
}

	}
	fclose(fp);
//printf("enter the polygon you want to fill");
//scanf("%d",&npoly1);
da[npoly1][f[npoly1]]=da[npoly1][1];
e[npoly1][f[npoly1]]=e[npoly1][1];
GLint a;
fscanf(fp1,"%d",&a);
nmid=a;
for(int i=1;i<=nmid;i++)
{
GLfloat s,d,f,g,h,j,k,l,m;
GLint fa;
	fscanf(fp1,"%f",&s);
	fscanf(fp1,"%f",&d);
	fscanf(fp1,"%f",&f);
	fscanf(fp1,"%f",&g);
	fscanf(fp1,"%f",&h);
	fscanf(fp1,"%f",&j);
	fscanf(fp1,"%f",&k);
	fscanf(fp1,"%f",&l);
	fscanf(fp1,"%f",&m);
	fscanf(fp1,"%d",&fa);
kar[i]=s;
kag[i]=d;
kab[i]=f;
kdr[i]=g;
kdg[i]=h;
kdb[i]=j;
ksr[i]=k;
ksg[i]=l;
ksb[i]=m;
phexpo[i]=fa;
}
/*for(int i=1;i<=a;i++)
{
printf("%f \t %f \t %f \n %f \t %f \t %f \n %f \t %f \t %f \n %d \n ",kar[i],kag[i],kab[i],kdr[i],kdg[i],kdb[i],ksr[i],ksg[i],ksb[i],phexpo[i]);
}*/
fclose(fp1);
GLfloat s,d,fa1,g,h,ja1,ka1,l,z,x,c;
	fscanf(fp2,"%f",&s);
	fscanf(fp2,"%f",&d);
	fscanf(fp2,"%f",&fa1);
	fscanf(fp2,"%f",&g);
	fscanf(fp2,"%f",&h);
	fscanf(fp2,"%f",&ja1);
	fscanf(fp2,"%f",&ka1);
	fscanf(fp2,"%f",&l);
	fscanf(fp2,"%f",&z);
	fscanf(fp2,"%f",&x);
	fscanf(fp2,"%f",&c);
{
xa=s;
xj=d;
xk=fa1;
lar=g;
lag=h;
lab=ja1;
lir=ka1;
lig=l;
lib=z;
fz=x;
k=c;
}
fclose(fp2);

//printf("%f \t %f \t %f \n %f \t %f \t %f \n %f \t %f \t %f \n %f \n %f \n",xa,xj,xk,lar,lag,lab,lir,lig,lib,fz,k);
for(int i=1;i<=a;i++)
{
  for(int j=1;j<=b[i];j++)
	{
		x1=(da[i][w[i][j]])-(da[i][q[i][j]]);
		ya1=(e[i][w[i][j]])-(e[i][q[i][j]]);
		z1=(ga[i][w[i][j]])-(ga[i][q[i][j]]);
		x2=(da[i][n[i][j]])-(da[i][w[i][j]]);
		y2=(e[i][n[i][j]])-(e[i][w[i][j]]);
		z2=(ga[i][n[i][j]])-(ga[i][w[i][j]]);
		crspx[i][j]=(z2*ya1)-(y2*z1);
		crspy[i][j]=-((x1*z2)-(x2*z1));
		crspz[i][j]=(x1*y2)-(x2*ya1);
	}
}

for(int i=1;i<=a;i++)
{
	for(int j=1;j<=f[i];j++)
		{	count[i][j]=0;
			nvx[i][j]=0;
			nvy[i][j]=0;
			nvz[i][j]=0;
		}
}
for(int i=1;i<=a;i++)
{
	for(int j=1;j<=f[i];j++)
		{	
			//float count=0;
			for(int k=1;k<=b[i];k++)
			{
				if( j==w[i][k] || j==q[i][k] ||  j==n[i][k])
				{	count[i][j]+=1;
					nvx[i][j]+=crspx[i][k];
					nvy[i][j]+=crspy[i][k];
					nvz[i][j]+=crspz[i][k];
				}
			}	

//printf("%d \t %d \t",i,j);
//printf("%f \t %f \t %f \n",(nvx[i][j]),(nvy[i][j]),(nvz[i][j]));
				nvx[i][j]=nvx[i][j]/count[i][j];									
				nvy[i][j]=nvy[i][j]/count[i][j];
				nvz[i][j]=nvz[i][j]/count[i][j];
				

			     	float q=(nvx[i][j]*nvx[i][j])+(nvy[i][j]*nvy[i][j])+(nvz[i][j]*nvz[i][j]);
				float v=sqrt(q);
			        nvx1[i][j]=(nvx[i][j]/v);
				nvy1[i][j]=(nvy[i][j]/v);		
				nvz1[i][j]=(nvz[i][j]/v);
		}
}
printf("enter \n 1>for outline gourand shading and half toning \n 2>for rasterized yz projection with painter algorithm implemented \n 3>for rasterized xz projection with painter algorithm implemented \n 4>for rasterized xy projection with painter algorithm implemented \n");
scanf("%d",&mass);
//printf("enter 1 for gourand shading 2 for halftonning ");
//scanf("%d",&apple);
npoly1=1;
ma=1;
    xmin1=xmax1=da[npoly1][q[npoly1][ma]];
    ymax1=ymin1=e[npoly1][q[npoly1][ma]];
zmax1=zmin1=ga[npoly1][q[npoly1][ma]];
painterxy();
intializez();
bubbleSortz();
//dispainxy();
//printArray();
narray();
incrment();
//prints();


painterxz();
intializey();
bubbleSorty();
painteryz();
intializex();
bubbleSortx();

printf("enter the material id");
		scanf("%d",&lam);
cz=2;
phong();

	/*Set up glut functions*/
    /** See https://www.opengl.org/resources/libraries/glut/spec3/spec3.html ***/
    
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    /*initialize variables, allocate memory, create buffers, etc. */
    //create window of size (win_width x win_height
    glutInitWindowSize(win_width,win_height);
    //windown title is "glut demo"
	glutCreateWindow("glut demo");
    
	/*defined glut callback functions*/
if(mass==1)
	glutDisplayFunc(display);
else if(mass==2)
	glutDisplayFunc(displaymas);
else if(mass==3)
	glutDisplayFunc(displaymasxz);
else if(mass==4)
	glutDisplayFunc(displaymasxy);
	glutReshapeFunc(reshape); //update GL on window size change
	glutMouseFunc(mouse);     //mouse button events
	glutMotionFunc(motion);   //mouse movement events
	glutKeyboardFunc(key);    //Keyboard events
	glutIdleFunc(idle);       //Function called while program is sitting "idle"
    
    //initialize opengl variables
    init();
    //start glut event loop
	glutMainLoop();
	return 0;
}

/*initialize gl stufff*/
void init()
{
    //set clear color (Default background to white)
	glClearColor(0.0,0.0,0.0,1.0);
    //checks for OpenGL errors
	check();
}

//called repeatedly when glut isn't doing anything else
void idle()
{
    //redraw the scene over and over again
	glutPostRedisplay();	
}

//this is where we render the screen
void display()
{ //apple=1;
    //clears the screen
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
    //clears the opengl Modelview transformation matrix
	glLoadIdentity();


//printf("enter your choice\n");
printf("enter\n 1>gourand shading \n 2>halftonning \n -1>exit \n");
scanf("%d",&apple);
switch(apple){
 case 1:printf("enter \n 1> xy projection \n 2>yz projection \n 3>xz projection \n 4>exit \n");
	int c;
	scanf("%d",&c);
	switch(c)
	{
	case 1:
		drawpolyxy();
		break;
	case 2:drawpolyyz();
		break;
	case 3:drawpolyxz();
		break;
	case 4:exit(1);
	}
	break;
case 2:printf("enter\n 1> xy projection \n 2>yz projection \n 3>xz projection \n 4>exit \n");
	int fas;
	scanf("%d",&fas);
	switch(fas)
	{
	case 1:drawpolyxy();
		break;
	case 2:drawpolyyz();
		break;
	case 3:drawpolyxz();
		break;
	case 4:exit(1);
	}
	break;
case -1:exit(1);
}
    //blits the current opengl framebuffer on the screen
    glutSwapBuffers();
    //checks for opengl errors
	check();
}
void displaymas()
{apple=1;
//clears the screen
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
    //clears the opengl Modelview transformation matrix
	glLoadIdentity();

drawpolyyz();
for(int ia=1;ia<=a;ia++)
{
for(int ja=1;ja<=b[ia];ja++)
{
npoly1=ia;
ma=calx[ia][ja];
calcsymin();

calcsymax();

calcszmin();
calcszmax();

float sa=zmin1+0.01;
while(sa<=zmax1)
{
intsb(sa);

//display1();
//sorta();

for(int i=1;i<c;i+=2)
lineDDA3(inter1[npoly1][i]*100,sa*100,inter1[npoly1][i+1]*100,sa*100);
//display2();
sa=sa+0.01;
}
}
}
glutSwapBuffers();
    //checks for opengl errors
	check();
}
void displaymasxz()
{apple=1;
glutSwapBuffers();
    //checks for opengl errors
	check();
for(int ia=1;ia<=a;ia++)
{
for(int ja=1;ja<=b[ia];ja++)
{
npoly1=ia;
ma=caly[ia][ja];
calcsxmin();

calcsxmax();

calcszmin();
calcszmax();

float sa=zmin1+0.01;
while(sa<=zmax1)
{
ints(sa);

//display1();
//sorta();

for(int i=1;i<c;i+=2)
lineDDA3(inter[npoly1][i]*100,sa*100,inter[npoly1][i+1]*100,sa*100);
//display2();
sa=sa+0.01;
}
}
}
drawpolyxz();
glutSwapBuffers();
    //checks for opengl errors
	check();
}
void displaymasxy()
{apple=1;
glutSwapBuffers();
    //checks for opengl errors
	check();
drawpolyxy();
for(int ia=1;ia<=a;ia++)
{
for(int ja=1;ja<=b[ia];ja++)
{
npoly1=ia;
ma=calz[ia][ja];
calcsxmin();

calcsxmax();

calcsymin();
calcsymax();

float sa=ymin1+0.01;
while(sa<=ymax1)
{
intsa(sa);

//display1();
//sorta();

for(int i=1;i<c;i+=2)
lineDDA3(inter[npoly1][i]*100,sa*100,inter[npoly1][i+1]*100,sa*100);
//display2();
sa=sa+0.01;
}
}
}
drawpolyxy();
glutSwapBuffers();
    //checks for opengl errors
	check();
}
//Draws a single "pixel" given the current grid size
//don't change anything in this for project 1


/*Gets called when display size changes, including initial craetion of the display*/
void reshape(int width, int height)
{
	/*set up projection matrix to define the view port*/
    //update the ne window width and height
	win_width = width;
	win_height = height;
    
    //creates a rendering area across the window
	glViewport(0,0,width,height);
    // up an orthogonal projection matrix so that
    // the pixel space is mapped to the grid space
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	glOrtho(0,grid_width,0,grid_height,-10,10);
    
    //clear the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    //set pixel size based on width, if the aspect ratio
    //changes this hack won't work as well
    pixel_size = width/(float)grid_width;
    
    //set pixel size relative to the grid cell size
    glPointSize(pixel_size);
    //check for opengl errors
	check();
}

//gets called when a key is pressed on the keyboard
void key(unsigned char ch, int x, int y)
{
	switch(ch)
	{
		default:
            //prints out which key the user hit
            printf("User hit the \"%c\" key\n",ch);
			break;
	}
    //redraw the scene after keyboard input
	glutPostRedisplay();
}


//gets called when a mouse button is pressed
void mouse(int button, int state, int x, int y)
{
    //print the pixel location, and the grid location
    printf ("MOUSE AT PIXEL: %d %d, GRID: %d %d\n",x,y,(int)(x/pixel_size),(int)((win_height-y)/pixel_size));
	switch(button)
	{
		case GLUT_LEFT_BUTTON: //left button
            printf("LEFT ");
            break;
		case GLUT_RIGHT_BUTTON: //right button
            printf("RIGHT ");
		default:
            printf("UNKNOWN "); //any other mouse button
			break;
	}
    if(state !=GLUT_DOWN)  //button released
        printf("BUTTON UP\n");
    else
        printf("BUTTON DOWN\n");  //button clicked
    
    //redraw the scene after mouse click
    glutPostRedisplay();
}

//gets called when the curser moves accross the scene
void motion(int x, int y)
{
    //redraw the scene after mouse movement
	glutPostRedisplay();
}

//checks for any opengl errors in the previous calls and
//outputs if they are present
void check()
{
	GLenum err = glGetError();
	if(err != GL_NO_ERROR)
	{
		printf("GLERROR: There was an error %s\n",gluErrorString(err) );
		exit(1);
	}
}

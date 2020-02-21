#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#define Y return
//#define R for
//#define e while
//#define I printf
//#define l int
//#define W if
//#define C y=v+111;H(x,v)*y++= *x
//#define H(a,b)for(a=b+11;a<b+89;a++)
//#define s(a)t=scanf("%d",&a)
//#define U Z printf
int E(int*v,int z,int f,int o);
/*#define Z printf("123\
45678\n");
for (x=V+11 ; x<V+89 ; x++) {
	putchar(".XO"[*x]);

	if ((x-V)%10 == 8) {
		x += 2;
		printf("%d\n" , (x-V)/10-1);
	}
}
*/






int V[1600],u,r[]={-1,-11,-10,-9,1,11,10,9},h[]={11,18,81,88},ih[]={22,27,72,77},bz,lv=60,*x,*y,m,t;
int S(int d,int*v,int f,int _,int a,int b)
{
	int c=0,*n=v+100,j=d<u-1?a:-9000,w,z,i,g=0,q=3-f;
	if(d>u){
		for(w=i=0;i<4;i++){
			w+=(m=v[h[i]])==f?300:m==q?-300:(t=v[ih[i]])==f?-50:t==q?50:0;
		}
		return w;
	}
	for(z=0 +11;z<0 +89;z++){
		if(E(v,z,f,100)){
			c++;
			w= -S(d+1,n,q,0,-b,-j);
			if(w>j){
				g=bz=z;
				j=w;
				if(w>=b||w>=8003){
					return w;
				}
			}
		}
	}
	if(!c){
		g=0;
		if(_){
			for(x=v+11;x<v+89;x++){
				c+= *x==f?1:*x==3-f?-1:0;
			}
			return c>0?8000+c:c-8000;
		}
		y=v+111;
		for(x=v+11;x<v+89;x++){
			*y++= *x;
		}
		j= -S(d+1,n,q,1,-b,-j);
	}
	bz=g;
	return d>=u-1?j+(c<<3):j;
}

int main(void)
{
	for(;t<1600;t+=100){
		for(m=0;m<100;m++){
			V[t+m]=m<11||m>88||(m+1)%10<2?3:0;
		}
	}
	printf("Level:");
	V[44]=V[55]=1;
	V[45]=V[54]=2;
	t=scanf("%d",&u);
	while(lv>0){
		printf("12345678\n");
		for(x=V+11;x<V+89;x++){
			putchar(".XO"[*x]);
			if((x-V)%10==8){
				x+=2;
				printf("%d\n",(x-V)/10-1);
			}
		} 
		do{
			printf("You:");
			t=scanf("%d",&m);
		}while(!E(V,m,2,0)&&m!=99);
		if(m!=99)
			lv--;
		if(lv<15&&u<10)
			u+=2;
		printf("12345678\n");
		for(x=V+11;x<V+89;x++){
			putchar(".XO"[*x]);
			if((x-V)%10==8){
				x+=2;
				printf("%d\n",(x-V)/10-1);
			}
		} 
		printf("Wait\n");
		printf("Value:%d\n",S(0,V,1,0,-9000,9000));
		printf("move: %d\n",(lv-=E(V,bz,1,0),bz));
	}
}

int E(int*v,int z,int f,int o)
{
	int*j,q=3-f,g=0,i,w,*k=v+z;
	if(*k==0) {
		for(i=7;i>=0;i--){
			j=k+(w=r[i]);
			while(*j==q){
				j+=w;
			}
			if(*j==f&&j-w!=k){
				if(!g){
					g=1;
					y=v+111;
					for(x=v+11;x<v+89;x++){
						*y++= *x;
					}
				}
				while(j!=k)*((j-=w)+o)=f;
			}
		}
	}

	return g;
}

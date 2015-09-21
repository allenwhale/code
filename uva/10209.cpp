#include<stdio.h> 
#include<math.h> 

int main() 
{ 
	double a,x,y,z,temp,pi_3,sqrt3,cx,cy,cz; 

	pi_3=2.0*acos(0.0)/3.0; 
	sqrt3=sqrt(3.0); 
	cx=(4.0-sqrt3-(2.0*pi_3)); 
	cy=(pi_3+(2.0*sqrt3)-4.0); 
	cz=(pi_3+1.0-sqrt3); 
	
	while(~scanf("%lf",&a))
	{ 
		x=a*a*cx; 
		y=a*a*cy; 
		z=a*a*cz; 	
		printf("%.3lf %.3lf %.3lf\n",z,y,x); 
	} 
}

#include<stdio.h>
 
int main()
{
    char type;
    double point[15][10] = {0};
    int pointnum = 0;
    while( (type = getchar()) != EOF && type != '*' )
    {
        point[pointnum][0] = 1;
        scanf( "%lf%lf%lf%lf", &point[pointnum][1], &point[pointnum][2], &point[pointnum][3], &point[pointnum][4]);
        pointnum++;
        getchar();
    }
    double pointx, pointy;
    int n = 1;
    while( scanf( "%lf%lf", &pointx, &pointy ) != EOF && !( pointx == 9999.9 && pointy == 9999.9 ) )
    {
        int i;
        int print = 0;
        for( i = 0 ; i < pointnum ; i++ )
            if( pointx > point[i][1] && pointx < point[i][3] && pointy < point[i][2] && pointy > point[i][4] )
            {
                printf( "Point %d is contained in figure %d\n", n, i+1 );
                print = 1;
            }
        if( !print )
            printf( "Point %d is not contained in any figure\n", n );
        n++;
    }
    return 0;
}

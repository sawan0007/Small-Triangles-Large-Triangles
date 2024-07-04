#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
	
    float area[n];
    double s,k;
    for (int i=0;i<n;i++){
        s=(tr[i].a+tr[i].b+tr[i].c)/2.0;
        k= sqrt(s*(s-tr[i].a)*(s-tr[i].b)*(s-tr[i].c));
        area[i]=k;
    }
    for(int i=1;i<n;i++){
        if(area[i]<area[i-1]){
            int j=i;
            while(j>0&& area[j]<area[j-1]){
                double temp=area[j];
                triangle temp_tr=tr[j];
                area[j]=area[j-1];
                tr[j]=tr[j-1];
                area[j-1]=temp;
                tr[j-1]=temp_tr;
                j--;
            }
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
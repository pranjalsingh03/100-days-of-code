#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

int n;
scanf("%d",&n);
int a[n], sum=0, i;
for(i=0;i<n;i++) scanf("%d",&a[i]);
for(i=0;i<n;i++) sum = sum + a[i];

printf("%d",sum);

return 0;
}







#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

int n;
scanf("%d",&n);
int a[n], i;
for(i=0;i<n;i++) scanf("%d",&a[i]);
for(i=n-1;i>=0;i--) printf("%d ",a[i]);

return 0;
}
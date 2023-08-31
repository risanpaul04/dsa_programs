#include<stdio.h>


int main(){
    int i, n;
    float ul, ll;
    printf("Number of instances: ");
    scanf("%d", &n);
    printf("Upper limit & lower limit: ");
    scanf("%f %f", &ul, &ll);
    float y_4=0.0, y_2=0.0, y_3=0.0, arr_x[n+1], arr_y[n+1];
    float h = (ul -ll)/n;
    float x = 0.0;
    for(int i=0; i<=n; i++){
        arr_x[i] = x;
        printf("x%d: %f\n", i, x);
        x = x + h;
    }
    printf("\n");

    // for(int i=0; i<=6; i++){
    //     printf("%f ", arr_x[i]);
    // }

    float y;
    for(i=0; i<=n; i++){
        arr_y[i] =1/(1+arr_x[i]*arr_x[i]);
    }
    printf("Value of All y: \n");
    for(i=0; i<=n; i++){
        printf("y%d: %f\n",i, arr_y[i]);
    }

    //Calculation of  the  integral using Simpson's one third method
    float res = arr_y[0] + arr_y[n];
    // for(i=1; i<n; i++){
    //     if(i%2!=0){
    //         y_4 += arr_y[i];
    //     }
    //     else{
    //         y_2 += arr_y[i];
    //     }
    // }

    for(i=1; i<n; i++){
        if(i%3==0){
            y_2 += arr_y[i];
        }
        else{
            y_3 += arr_y[i];
        }
    }

    // float res_simp13 = h/3*(res + 4*y_4 + 2*y_2);
    // printf("\nResult using Simpson's one third rule: %f\n", res_simp13);

    float res_simp38 = 3*h/8 * (res + 3*y_3 + 2*y_2);
    printf("\nResult using Simpson's three eighth rule: %f\n", res_simp38);

    return 0;
}
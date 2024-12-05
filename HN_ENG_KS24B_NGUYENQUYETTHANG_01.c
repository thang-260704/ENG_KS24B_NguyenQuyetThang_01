#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int a[100005],tg[100005],n,gt,vt,d,dem,max1,max2,checkTM;
int cmp(const void *ptr1, const void *ptr2){
    int *x = (int*)ptr1;
    int *y = (int*)ptr2;
    if(*x < *y)return -1;
    else return 1;
}
int sohoanhao(int a){
  int s=0;
  for(int i=1;i<=a/2;i++)if(a%i==0)s+=i;
  if(s=a)return 1;
  else return 0;
}
int main(){
    do{
       printf("MENU\n1.Nhap so phan tu va gia tri cho mang\n2.In ra cac phan tu trong mang\n3.Dem so luong cac so hoan hao co trong mang\n4.Tim gia tri nho thu 2 trong mang\n5.Them mot phan tu vao vi tri yeu cau\n6.Xoa phan tu\n7.Sap xep mang theo thu tu tang dan\n8.Tim kiem phan tu theo yeu cau\n9.Sap xep lai mang sao cho toan bo so le dung truoc so chan dung sau\n10.Kiem tra xem mang co phai tang dan hay khong\n11.Thoat chuong trinh\nLua chon cua ban: ");
       scanf("%d",&d);
       switch(d){
        case 1:
         printf("nhap so phan tu: ");
         scanf("%d",&n);
         printf("nhap gia tri phan tu: ");
         for(int i=0;i<n;i++)scanf("%d",&a[i]);
         break;
        case 2:
         printf("gia tri cac phan tu trong mang:\n");
         for(int i=0;i<n;i++)printf("arr[%d] =%d,",i,a[i]);
         printf("\n");
         break;
        case 3:
         for(int i=0;i<n;i++)if(sohoanhao(a[i]))dem++;
         printf("So luong so hoan hao: %d\n",dem);
         break;
        case 4:
         for(int i=0;i<n;i++)max1=fmax(max1,a[i]);
         for(int i=0;i<n;i++)if(a[i]>max2&&a[i]<max1)max2=a[i];
         printf("Phan tu lon thu 2 trong mang: %d\n",max2);
         break;
        case 5:
         checkTM=0;
         printf("Nhap gia tri can them vao mang: ");
         scanf("%d",&gt);
         for(int i=0;i<n;i++){
         if(a[i]==gt)checkTM=1;
                }
         if(checkTM!=0)printf("Gia tri da co trong mang\n");
         else{
         printf("Nhap vi tri can them vao mang: ");
         scanf("%d",&vt);
         if(vt==n){
         a[n]=gt;
          n++;
                    }
         else if(vt>n){
         printf("Vi tri nhap vao khong hop le\n");
                    }
         else{
         for(int i=n;i>=vt;i--)a[i]=a[i-1];
         a[vt]=gt;
         n++;
         printf("Da them gia tri theo yeu cau\n");
                    }
                break;
        case 6:
         printf("Nhap vi tri can xoa: ");
         scanf("%d",&vt);
         if(vt>=n)printf("vi tri xoa khong hop le");
         else{
                    for(int i=vt;i<n-1;i++)a[i]=a[i+1];
                    --n;
                    printf("Da xoa theo yeu cau\n");
               }
        case 10:
                checkTM=0;
                for(int i=0;i<n;i++)tg[i]=a[i];
                qsort(tg,n,sizeof(int),cmp);
                for(int i=0;i<n;i++)if(a[i]!=tg[i])checkTM++;
                if(checkTM==0)printf("Mang da duoc sap xep\n");
                else printf("Mang chua duoc sap xep\n");
                break;
                default:
                       continue;
         }
         
               }
    }while(d!=11);
}


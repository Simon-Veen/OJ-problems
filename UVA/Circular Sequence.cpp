#include <stdio.h>
#include <string.h>
char box[105],pd='Z';
int pz,ypz,j,cnt;
int main()
{
    int k=0;
    scanf("%d",&k);
    for(int p=1;p<=k;p++)
    {
        scanf("%s",box);
        pd='Z';
        for(int i=0;i<strlen(box);i++)
        {
            if(pd>box[i]){pd=box[i];pz=i;}
        }
        for(int i=0;i<strlen(box);i++)
        {
            if(box[pz]==box[i]&&pz!=i)
            {
                cnt=1;
                ypz=pz;j=i;
                while(cnt<=strlen(box))
                {
                    (ypz+1==strlen(box))?ypz=0:ypz+=1;
                    (j+1==strlen(box))?j=0:j+=1;
                    if(box[ypz]>box[j]){pz=i;break;}
                    if(box[ypz]<box[j])break;
                    cnt+=1;
                }
            }
        }
        cnt=0;
        while(cnt<strlen(box))
        {
            if(pz==strlen(box))pz=0;
            printf("%c",box[pz++]);
            cnt+=1;
        }
        printf("\n");
    }
}


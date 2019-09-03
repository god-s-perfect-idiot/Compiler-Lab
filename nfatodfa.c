#include<stdio.h>
#include<string.h>

int n,dfa[100][100][100],dfalen[100][100],sig,fin[100],finc,mn_mat[100][100],minlen=0,min[100][100],minr[100];
char sym[100];

void showdfa(){
	
	printf("\n\n");
	
	for(int i=0;i<sig;i++){
		printf("\t|  %c",sym[i]);
	}
	printf("\n_________________________________________");
	for(int i=0;i<n;i++){
		printf("\nq%d",i);
		for(int j=0;j<sig;j++){
			printf("\t|  ");
			for(int k=0;k<dfalen[i][j];k++){
				printf("%d ",dfa[i][j][k]);
			} 
		}
	}
}

int check(int a,int b[100],int blen){

	int yes=1;
	for(int i=0;i<blen;i++){
	
		if(b[i]==a)
			yes=0;
	}
	
	if(yes)
		return 1;
	return 0;

}

bool areEqual(int arr1[], int arr2[], int n, int m) 
{ 

    if (n != m) 
        return false; 
  
    sort(arr1, arr1 + n); 
    sort(arr2, arr2 + m); 
  
    for (int i = 0; i < n; i++) 
        if (arr1[i] != arr2[i]) 
            return false; 
   
    return true; 
} 

void convert(int a[100],int len){
	
	int temp[100],currlen=0,newlen=0;
	for(int i=0;i<len;i++){
	
		for(int j=0;j<sig;j++){
		
			int ind=0;
			newlen=currlen;
			for(int k=currlen;k<(currlen+dfalen[a[i]][j]);k++){				
				if(check(dfa[a[i]][j][ind],temp,newlen)){
					temp[k]=dfa[a[i]][j][ind];	
					ind +=1;
					newlen+=1;
				}
			}
			currlen=newlen;
			if(dfalen[a[i]][j]==0){
				temp[currlen]=-1;
				currlen+=1;
			}
		}
	
	}

	for(int i=0;i<minlen;i++){
		if(currlen==minr[minlen]){
			int match=0;
			for(int j=0;j<minr[minlen];j++){
				if(min[i][j]==
			}
		}
	}

}

void main(){

	char temp[100];

	printf("\n\nEnter node count:");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dfalen[i][j]=0;
		}
	}
	
	printf("\n\nEnter Alphabet length:");
	scanf("%d",&sig);
	
	printf("\n\nEnter input symbols:");
	for(int i=0;i<sig;i++){
		scanf(" %c",&sym[i]);
	}
		
	printf("\n\n");
	
	for(int i=0;i<n;i++){
		for(int j=0;j<sig;j++){
			
			printf("transition count of q%d on %c:",i,sym[j]);
			scanf("%d", &dfalen[i][j]);
			printf("delta(q%d,%c): ",i,sym[j]);
			for(int k=0;k<dfalen[i][j];k++){
				scanf("%d",&dfa[i][j][k]);
			} 	
		}
	}
	
	printf("\n\n");
	
	printf("Enter number of final states: ");
	scanf("%d",&finc);
	
	printf("\n\n");
	printf("Enter final states: ");
	for(int i=0;i<finc;i++){
		scanf("%d",&fin[i]);
	}

	int t[100];
	t[0]=0;
	t[1]=1;
	convert(t,2);

}

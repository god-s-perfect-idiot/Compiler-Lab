#include<stdio.h>
#include<string.h>

int n,dfa[100][100],sig,fin[100],finc,mn_mat[100][100],minlen=0,min[100][100],minr[100];
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
			printf("\t|  %d",dfa[i][j]);
		}
	}
}

int checkrow(int a){
	
	for(int i=0;i<minlen;i++){
	
		for(int j=0;j<minr[i];j++){
			
			if(a==min[i][j])
				return i;
		}
	}
	
	return 1001;
}

int checkfin(int a,int b){
	
	int x=0,y=0;
	
	for(int i=0;i<finc;i++){
		if(fin[i]==a)
			x=1;
		if(fin[i]==b)
			y=1;
	}
	
	if((x==0 && y==1) || (x==1 && y==0))
		return 1;
	else
		return 0;
	
}

int checktrans(int a,int b,int c){
	
	int p,q;
	
	p=dfa[a][c];
	q=dfa[b][c];
	
	if(mn_mat[p][q]==1)
		return 1;
	else
		return 0;
}

void main(){
	
	int empty=1,changed;
	
	printf("\n\nEnter node count:");
	scanf("%d",&n);
	
	printf("\n\nEnter Alphabet length:");
	scanf("%d",&sig);
	
	printf("\n\nEnter input symbols:");
	for(int i=0;i<sig;i++){
		scanf(" %c",&sym[i]);
	}
		
	printf("\n\n");
	
	for(int i=0;i<n;i++){
		for(int j=0;j<sig;j++){
			printf("delta(q%d,%c): ",i,sym[j]);
			scanf("%d",&dfa[i][j]);
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
	
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(checkfin(i,j)){
				mn_mat[i][j]=1;
			}
		}
	}
	
	
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(mn_mat[i][j]==0){
				empty=0;
			}
		}
	}
	
	while(!empty){
		changed=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				for(int k=0;k<sig;k++){
					if(checktrans(i,j,k) && mn_mat[i][j]!=1){
						mn_mat[i][j]=1;
						changed=1;
					}
				}
			}
		}
		if(!changed)
			break;
		
	}
	
	
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(mn_mat[i][j]==0){
				int indx=checkrow(i);
				int indy=checkrow(j);
				
				if(indx==1001 && indy==1001){
					min[minlen][0]=i;
					min[minlen][1]=j;
					minr[minlen]+=2;
					minlen+=1;
				}
				else if(indx!=1001 && indy==1001){
					int index=minr[indx];
					min[indx][index]=j;
					minr[indx]+=1;
				}
				else if(indy!=1001 && indx==1001){
					int index=minr[indy];
					min[indy][index]=i;
					minr[indy]+=1;
				}
			}
		}
	}
	
	for(int i=0;i<n;i++){
		if(checkrow(i)==1001){
			min[minlen][0]=i;
			minr[minlen]+=1;
			minlen+=1;
		}
	}
	
	printf("\n\n");
	
	for(int i=0;i<sig;i++){
		printf("\t\t  %c",sym[i]);
	}
	printf("\n_________________________________________\n");
	
	for(int i=0;i<minlen;i++){
		for(int j=0;j<minr[i];j++){
			printf("%d ",min[i][j]);
		}
		for(int j=0;j<sig;j++){
			int found=checkrow(dfa[min[i][0]][j]);
			printf("\t\t  ");
			for(int j=0;j<minr[found];j++){
				printf("%d ",min[found][j]);
			}
		}
		printf("\n");
	}
	
	showdfa();
}

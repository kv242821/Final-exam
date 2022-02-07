#include "function.h"
//	MAIN
int main(){
	char cmd[50];
	int list_id,coef,exp,i;
	node *cur;
	poly[1]=NULL;	poly[2]=NULL;
	poly[3]=NULL;	poly[4]=NULL;

	while(1){
		scanf("%s",cmd);

		if(strcmp(cmd,"insert")==0){
			scanf("%d %d %d",&list_id,&coef,&exp);
			if(coef==0)continue;
			poly[list_id]=insert(poly[list_id],coef,exp);
		}
		else if(strcmp(cmd,"display")==0){
			scanf("%d",&list_id);
			display(poly[list_id]);
		}
		else if(strcmp(cmd,"sort")==0){
			scanf("%d",&list_id);
			sort_exp(poly[list_id]);
			display(poly[list_id]);
		}
		else if(strcmp(cmd,"add")==0){
			reset(poly[3]);			
			poly[3]=add(poly[1],poly[2]);
			sort_exp(poly[3]);
			display(poly[3]);
		}
		else if(strcmp(cmd,"multiply")==0){
			reset(poly[4]);	
			poly[4]=multiply(poly[1],poly[2]);
			sort_exp(poly[4]);
			display(poly[4]);		
		}
		else if(strcmp(cmd,"space")==0){
			scanf("%d",&list_id);
			i=0;
			for(cur=poly[list_id];cur!=NULL;cur=cur->next) 
			if(cur->term.coef!=0) i+=10;
			printf("%d\n",i);
		}
		else if(strcmp(cmd,"reset")==0){
			scanf("%d",&list_id);
			reset(poly[list_id]);
		}
		else if(strcmp(cmd,"***")==0) {
			for(i=1;i<=4;i++) reset(poly[i]);
			return 0;
		}	
	}
	return 0;
}


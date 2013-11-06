//lixian xie
//write some simple system calls.

void printString(char* str){
	int i;
	for(i=0;str[i]!='\0';i++){
		interrupt(0x10,0xE*+str[i],0,0,0);	
	}	
}

int main(){
	printString("Hello World");	
	while(1){
		//todo
	}
	return 0;
}

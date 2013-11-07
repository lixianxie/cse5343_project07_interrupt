//lixian xie
//write some simple system calls.

void printString(char* str);
void readString(char* str);

int main(){
	char line[80];
	printString("Enter a line: ");
	readString(line);
 	printString(line);	
	while(1){
		//todo
	}
	return 0;
}

void printString(char* str){
	int i;
	for(i=0;str[i]!=0;i++){
		interrupt(0x10,0xE*256+str[i],0,0,0);			
	}	
}

void readString(char* str){
	int i=0;
	char tempChar;
	tempChar=interrupt(0x16,0,0,0,0);
	while(tempChar!=0xd){
		interrupt(0x10,0xE*256+tempChar,0,0,0);
		if(tempChar!=0x8)str[i]=tempChar;		
		tempChar=interrupt(0x16,0,0,0,0);
		i++;
	}
	str[i]=0xa;	   //jump to next line of same column
	str[i+1]=0xd;  //return to head of current line
	str[i+2]=0x0;  //end of string
	interrupt(0x10,0xE*256+0xa,0,0,0);
	interrupt(0x10,0xE*256+0xd,0,0,0);
}




//lixian xie
//a simple kernel that displays a message.



int main(){
	char str[100]="Hello World";
	int i=0;
	while(str[i]!='\0'){
		putInMemory(0xB000,32768+2*i,str[i]); //32768=0x8000
		putInMemory(0xB000,32769+2*i,0x7);
		i++;
	}

	while(1){
		//todo
	}
	return 0;
}

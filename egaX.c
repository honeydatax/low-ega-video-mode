// need file libdos.c to be compile in directory
//bcc -x -i -L -Md hello.c -o HELLO.COM
#define varn 0x0080
#define lowega 0xd
#define VIDEO 0xA000
#define stdout 0 
#define lpt 2 
#define com1 3 
#define blue 1
#define brish 8
int VID;
int ii;
void screens(n);
int getptr();
void backs(address,count,color);
void refresh(address,count,addr2);
void setcolor(color);
void rect(rectx,recty,rectx1,recty1,color);
void vline(vlinex,vliney,vlinex1,vliney1,color);
void trig(x,y,size,color);
void rxline(x,y,x1,y1,color);
void lxline(x,y,x1,y1,color);
int getkey();

int main(){
	int n=0;
	int nnn=0;
	int e;
	int ee;
	int xx;
	int x=5;
	int y=5;
	int x1=50;
	int y1=50;
	int color=2;
	int unsigned size=(320/8)*200; 
	char c;
	screens(lowega);
	VID=getptr()+0x2000;
	backs(VID,(int)size,blue+brish);
		// X
	rxline(0,0,319,199,blue);
		// X
	lxline(0,199,319,0,blue);
	refresh(VIDEO,size,VID);
		asm	"db 0xb4,0,0xcd,0x21";
		
	return 0;
}



void screens(n)
int n;
{
	int *c;
	c = (int * ) varn;
	*(c + 0) = n;


	asm	"db 0x1E,0x56,0x8C,0xC8,0x8E,0xD8,0xBE,0x80,0x00,0x2E,0x8A,0x04,0xB4,0x00,0xCD,0x10,0x5E,0x1F";
}



int getptr()
{
	int *c;
	c = (int * ) varn;

	asm	"db 0x8C,0xC8,0x2E,0xA3,0x80,0x0";
	return *(c + 0);
}

void backs(address,count,color)
int address;
int count;
int color;
{
	int *c;
	c = (int * ) varn;
	if((color & 1)!=0){
		*(c + 0)=address;
		*(c + 1)=count;
		*(c + 2)=255;
		asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x0E,0x82,0x00,0x8B,0x16,0x84,0x00,0xA1,0x80,0x00,0x50,0x07,0x88,0xD0,0x31,0xD2,0x89,0xD7,0x90,0xFC,0xF3,0xAA,0x07,0x1F";
	}else{
		*(c + 0)=address;
		*(c + 1)=count;
		*(c + 2)=0;
		asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x0E,0x82,0x00,0x8B,0x16,0x84,0x00,0xA1,0x80,0x00,0x50,0x07,0x88,0xD0,0x31,0xD2,0x89,0xD7,0x90,0xFC,0xF3,0xAA,0x07,0x1F";
	}

	if((color & 2) !=0){
		*(c + 0)=address+0x1000;
		*(c + 1)=count;
		*(c + 2)=255;
		asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x0E,0x82,0x00,0x8B,0x16,0x84,0x00,0xA1,0x80,0x00,0x50,0x07,0x88,0xD0,0x31,0xD2,0x89,0xD7,0x90,0xFC,0xF3,0xAA,0x07,0x1F";
	}else{
		*(c + 0)=address+0x1000;
		*(c + 1)=count;
		*(c + 2)=0;
		asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x0E,0x82,0x00,0x8B,0x16,0x84,0x00,0xA1,0x80,0x00,0x50,0x07,0x88,0xD0,0x31,0xD2,0x89,0xD7,0x90,0xFC,0xF3,0xAA,0x07,0x1F";
	}
	if((color & 4) !=0){
		*(c + 0)=address+0x2000;
		*(c + 1)=count;
		*(c + 2)=255;
		asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x0E,0x82,0x00,0x8B,0x16,0x84,0x00,0xA1,0x80,0x00,0x50,0x07,0x88,0xD0,0x31,0xD2,0x89,0xD7,0x90,0xFC,0xF3,0xAA,0x07,0x1F";
	}else{
		*(c + 0)=address+0x2000;
		*(c + 1)=count;
		*(c + 2)=0;
		asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x0E,0x82,0x00,0x8B,0x16,0x84,0x00,0xA1,0x80,0x00,0x50,0x07,0x88,0xD0,0x31,0xD2,0x89,0xD7,0x90,0xFC,0xF3,0xAA,0x07,0x1F";
	}

	if((color & 8) !=0){
		*(c + 0)=address+0x3000;
		*(c + 1)=count;
		*(c + 2)=255;
		asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x0E,0x82,0x00,0x8B,0x16,0x84,0x00,0xA1,0x80,0x00,0x50,0x07,0x88,0xD0,0x31,0xD2,0x89,0xD7,0x90,0xFC,0xF3,0xAA,0x07,0x1F";
	}else{
		*(c + 0)=address+0x3000;
		*(c + 1)=count;
		*(c + 2)=0;
		asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x0E,0x82,0x00,0x8B,0x16,0x84,0x00,0xA1,0x80,0x00,0x50,0x07,0x88,0xD0,0x31,0xD2,0x89,0xD7,0x90,0xFC,0xF3,0xAA,0x07,0x1F";
	}


	
}


void refresh(address,count,addr2)
int address;
int count;
int addr2;
{
	int *c;
	c = (int * ) varn;
	setcolor(1);
	*(c + 0)=address;
	*(c + 1)=count;
	*(c + 2)=addr2;
	asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x1E,0x84,0x00,0x8B,0x0E,0x82,0x00,0xA1,0x80,0x00,0x50,0x07,0x53,0x1F,0x31,0xD2,0x89,0xD6,0x89,0xD7,0x90,0xFC,0xF3,0xA4,0x07,0x1F";
	setcolor(2);
	*(c + 0)=address;
	*(c + 1)=count;
	*(c + 2)=addr2+0x1000;
	asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x1E,0x84,0x00,0x8B,0x0E,0x82,0x00,0xA1,0x80,0x00,0x50,0x07,0x53,0x1F,0x31,0xD2,0x89,0xD6,0x89,0xD7,0x90,0xFC,0xF3,0xA4,0x07,0x1F";
	setcolor(4);
	*(c + 0)=address;
	*(c + 1)=count;
	*(c + 2)=addr2+0x2000;
	asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x1E,0x84,0x00,0x8B,0x0E,0x82,0x00,0xA1,0x80,0x00,0x50,0x07,0x53,0x1F,0x31,0xD2,0x89,0xD6,0x89,0xD7,0x90,0xFC,0xF3,0xA4,0x07,0x1F";
	setcolor(8);
	*(c + 0)=address;
	*(c + 1)=count;
	*(c + 2)=addr2+0x3000;
	asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x1E,0x84,0x00,0x8B,0x0E,0x82,0x00,0xA1,0x80,0x00,0x50,0x07,0x53,0x1F,0x31,0xD2,0x89,0xD6,0x89,0xD7,0x90,0xFC,0xF3,0xA4,0x07,0x1F";
	
}

void setcolor(color)
int color;
{
	int *c;
	c = (int * ) varn;
		*(c + 0)=color;
		asm	"db 0x1E,0x06,0x0E,0x1F,0x2E,0x8A,0x26,0x80,0x00,0xBA,0xC4,0x03,0xB0,0x02,0xEF,0x07,0x1F";
	
}

void rect(rectx,recty,rectx1,recty1,color)
int rectx;
int recty;
int rectx1;
int recty1;
int color;
{
	int r;
	int ir;
	int xx;
	int yy;
	int nx;
	int ny;
	int xx1;
	int yy1;
	int xxx;
	int yyy;
	int xxa;
	int *c;
	int gg=0;
	int unsigned size=(320/8)*200; 
	c = (int * ) varn;
	xx=rectx;
	yy=recty;
	xx1=rectx1;
	yy1=recty1;
	if (xx>320)xx=320;
	if (xx1>320)xx1=320;
	if (yy>200)yy=200;
	if (yy1>200)yy1=200;
	if (xx<0)xx=0;
	if (xx1<0)xx1=0;
	if (yy<0)yy=0;
	if (yy1<0)yy1=0;
	xx=xx/8;
	xx1=xx1/8;
	if (xx<=xx1 && yy<=yy1 && ((color & 1) !=0)){
		xxa=xx1-xx;
		if (xxa<1)xxa=1;
		yyy=yy1-yy;
		if (yyy<1)yyy=1;
		xxx=yy*40+xx;
		nx=40-xxa;
		*(c + 0)=VID;
		*(c + 1)=xxx;
		*(c + 2)=xxa;
		*(c + 3)=nx;
		*(c + 4)=yyy;
		*(c + 5)=255;
	}
	if (xx<=xx1 && yy<=yy1 && ((color & 1) ==0)){
		xxa=xx1-xx;
		if (xxa<1)xxa=1;
		yyy=yy1-yy;
		if (yyy<1)yyy=1;
		xxx=yy*40+xx;
		nx=40-xxa;
		*(c + 0)=VID;
		*(c + 1)=xxx;
		*(c + 2)=xxa;
		*(c + 3)=nx;
		*(c + 4)=yyy;
		*(c + 5)=0;
	}
		
	if (xx<=xx1 && yy<=yy1 ){
		asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x3E,0x82,0x00,0x8B,0x36,0x86,0x00,0x8B";
		asm "db 0x16,0x8A,0x00,0x8B,0x1E,0x88,0x00,0x8B,0x0E,0x84,0x00,0xA1,0x80,0x00";
		asm "db 0x50,0x07,0x88,0xD0,0x31,0xD2,0x51,0x90,0x59,0x51,0x90,0xFC,0xF3,0xAA";
		asm "db 0xF8,0x01,0xF7,0x4B,0x39,0xD3,0x75,0xF1,0x58,0x07,0x1F";
	}		



	if (xx<=xx1 && yy<=yy1 && ((color & 2) !=0)){
		xxa=xx1-xx;
		if (xxa<1)xxa=1;
		yyy=yy1-yy;
		if (yyy<1)yyy=1;
		xxx=yy*40+xx;
		nx=40-xxa;
		*(c + 0)=VID+0x1000;
		*(c + 1)=xxx;
		*(c + 2)=xxa;
		*(c + 3)=nx;
		*(c + 4)=yyy;
		*(c + 5)=255;
	}	
	if (xx<=xx1 && yy<=yy1 && ((color & 2) ==0)){
		xxa=xx1-xx;
		if (xxa<1)xxa=1;
		yyy=yy1-yy;
		if (yyy<1)yyy=1;
		xxx=yy*40+xx;
		nx=40-xxa;
		*(c + 0)=VID+0x1000;
		*(c + 1)=xxx;
		*(c + 2)=xxa;
		*(c + 3)=nx;
		*(c + 4)=yyy;
		*(c + 5)=0;
	}	

	if (xx<=xx1 && yy<=yy1){
		asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x3E,0x82,0x00,0x8B,0x36,0x86,0x00,0x8B";
		asm "db 0x16,0x8A,0x00,0x8B,0x1E,0x88,0x00,0x8B,0x0E,0x84,0x00,0xA1,0x80,0x00";
		asm "db 0x50,0x07,0x88,0xD0,0x31,0xD2,0x51,0x90,0x59,0x51,0x90,0xFC,0xF3,0xAA";
		asm "db 0xF8,0x01,0xF7,0x4B,0x39,0xD3,0x75,0xF1,0x58,0x07,0x1F";
	}		
	if (xx<=xx1 && yy<=yy1 && ((color & 4) !=0)){
		xxa=xx1-xx;
		if (xxa<1)xxa=1;
		yyy=yy1-yy;
		if (yyy<1)yyy=1;
		xxx=yy*40+xx;
		nx=40-xxa;
		*(c + 0)=VID+0x2000;
		*(c + 1)=xxx;
		*(c + 2)=xxa;
		*(c + 3)=nx;
		*(c + 4)=yyy;
		*(c + 5)=255;
	}	
	if (xx<=xx1 && yy<=yy1 && ((color & 4) ==0)){
		xxa=xx1-xx;
		if (xxa<1)xxa=1;
		yyy=yy1-yy;
		if (yyy<1)yyy=1;
		xxx=yy*40+xx;
		nx=40-xxa;
		*(c + 0)=VID+0x2000;
		*(c + 1)=xxx;
		*(c + 2)=xxa;
		*(c + 3)=nx;
		*(c + 4)=yyy;
		*(c + 5)=0;
	}	

	if (xx<=xx1 && yy<=yy1 ){
		asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x3E,0x82,0x00,0x8B,0x36,0x86,0x00,0x8B";
		asm "db 0x16,0x8A,0x00,0x8B,0x1E,0x88,0x00,0x8B,0x0E,0x84,0x00,0xA1,0x80,0x00";
		asm "db 0x50,0x07,0x88,0xD0,0x31,0xD2,0x51,0x90,0x59,0x51,0x90,0xFC,0xF3,0xAA";
		asm "db 0xF8,0x01,0xF7,0x4B,0x39,0xD3,0x75,0xF1,0x58,0x07,0x1F";
	}		




	if (xx<=xx1 && yy<=yy1 && ((color & 8) !=0)){
		xxa=xx1-xx;
		if (xxa<1)xxa=1;
		yyy=yy1-yy;
		if (yyy<1)yyy=1;
		xxx=yy*40+xx;
		nx=40-xxa;
		*(c + 0)=VID+0x3000;
		*(c + 1)=xxx;
		*(c + 2)=xxa;
		*(c + 3)=nx;
		*(c + 4)=yyy;
		*(c + 5)=255;
	}	
	if (xx<=xx1 && yy<=yy1 && ((color & 8) ==0)){
		xxa=xx1-xx;
		if (xxa<1)xxa=1;
		yyy=yy1-yy;
		if (yyy<1)yyy=1;
		xxx=yy*40+xx;
		nx=40-xxa;
		*(c + 0)=VID+0x3000;
		*(c + 1)=xxx;
		*(c + 2)=xxa;
		*(c + 3)=nx;
		*(c + 4)=yyy;
		*(c + 5)=0;
	}	
	if (xx<=xx1 && yy<=yy1 ){
		asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x3E,0x82,0x00,0x8B,0x36,0x86,0x00,0x8B";
		asm "db 0x16,0x8A,0x00,0x8B,0x1E,0x88,0x00,0x8B,0x0E,0x84,0x00,0xA1,0x80,0x00";
		asm "db 0x50,0x07,0x88,0xD0,0x31,0xD2,0x51,0x90,0x59,0x51,0x90,0xFC,0xF3,0xAA";
		asm "db 0xF8,0x01,0xF7,0x4B,0x39,0xD3,0x75,0xF1,0x58,0x07,0x1F";
	}		

	
}



void vline(vlinex,vliney,vlinex1,vliney1,color)
int vlinex;
int vliney;
int vlinex1;
int vliney1;
int color;
{
	int x=vlinex;
	int y=vliney;
	int x1=vlinex;
	int y1=vliney1;
	int x2;
	int *c;
	if(x!=x1)goto ends;
	if(x<0 || x>319)goto ends;
	if(y<0 )y=0;
	if(y1<0 )y1=0;
	if(y>199)y=199;
	if(y1>199)y1=199;
	if(y>y1)goto ends;
	x1=x1-(x1/8*8);
	x1=128 >> x1;
	x=y*40+(x/8);
	y=y1-y;
	if(y<1)y=1;
	c = (int * ) varn;
	if((color & 1)!=0){
		*(c + 0)=VID;
		*(c + 1)=x;
		*(c + 2)=y;
		*(c + 3)=40;
		*(c + 4)=x1;
		asm	"db 0x1E,0x06,0x50,0x53,0x51,0x52,0x56,0x57,0x2E,0xA1,0x86,0x00,0x89,0xC6,0x2E,0x8B,0x1E,0x82,0x00,0x2E,0x8B,0x0E,0x84,0x00,0x2E,0x8A,0x16,0x88,0x00,0x2E,0xA1,0x80,0x00,0x8E,0xD8,0x90,0x3E,0x8A,0x07,0x08,0xD0,0x3E,0x88,0x07,0xF8,0x01,0xF3,0x49,0x83,0xF9,0x00,0x75,0xEE,0x5F,0x5E,0x5A,0x59,0x5B,0x58,0x07,0x1F";
	}else{
		*(c + 0)=VID;
		*(c + 1)=x;
		*(c + 2)=y;
		*(c + 3)=40;
		*(c + 4)=x1;
		asm	"db 0x1E,0x06,0x50,0x53,0x51,0x52,0x56,0x57,0x2E,0xA1,0x86,0x00,0x89,0xC6,0x2E,0x8B,0x1E,0x82,0x00,0x2E,0x8B,0x0E,0x84,0x00,0x2E,0x8A,0x16,0x88,0x00,0x2E,0xA1,0x80,0x00,0x8E,0xD8,0xF6,0xD2,0x90,0x3E,0x8A,0x07,0x20,0xD0,0x3E,0x88,0x07,0xF8,0x01,0xF3,0x49,0x83,0xF9,0x00,0x75,0xEE,0x5F,0x5E,0x5A,0x59,0x5B,0x58,0x07,0x1F";
	}
	
	if((color & 2)!=0){
		*(c + 0)=VID+0x1000;
		*(c + 1)=x;
		*(c + 2)=y;
		*(c + 3)=40;
		*(c + 4)=x1;
		asm	"db 0x1E,0x06,0x50,0x53,0x51,0x52,0x56,0x57,0x2E,0xA1,0x86,0x00,0x89,0xC6,0x2E,0x8B,0x1E,0x82,0x00,0x2E,0x8B,0x0E,0x84,0x00,0x2E,0x8A,0x16,0x88,0x00,0x2E,0xA1,0x80,0x00,0x8E,0xD8,0x90,0x3E,0x8A,0x07,0x08,0xD0,0x3E,0x88,0x07,0xF8,0x01,0xF3,0x49,0x83,0xF9,0x00,0x75,0xEE,0x5F,0x5E,0x5A,0x59,0x5B,0x58,0x07,0x1F";
	}else{
		*(c + 0)=VID+0x1000;
		*(c + 1)=x;
		*(c + 2)=y;
		*(c + 3)=40;
		*(c + 4)=x1;
		asm	"db 0x1E,0x06,0x50,0x53,0x51,0x52,0x56,0x57,0x2E,0xA1,0x86,0x00,0x89,0xC6,0x2E,0x8B,0x1E,0x82,0x00,0x2E,0x8B,0x0E,0x84,0x00,0x2E,0x8A,0x16,0x88,0x00,0x2E,0xA1,0x80,0x00,0x8E,0xD8,0xF6,0xD2,0x90,0x3E,0x8A,0x07,0x20,0xD0,0x3E,0x88,0x07,0xF8,0x01,0xF3,0x49,0x83,0xF9,0x00,0x75,0xEE,0x5F,0x5E,0x5A,0x59,0x5B,0x58,0x07,0x1F";
	}

	if((color & 4)!=0){
		*(c + 0)=VID+0x2000;
		*(c + 1)=x;
		*(c + 2)=y;
		*(c + 3)=40;
		*(c + 4)=x1;
		asm	"db 0x1E,0x06,0x50,0x53,0x51,0x52,0x56,0x57,0x2E,0xA1,0x86,0x00,0x89,0xC6,0x2E,0x8B,0x1E,0x82,0x00,0x2E,0x8B,0x0E,0x84,0x00,0x2E,0x8A,0x16,0x88,0x00,0x2E,0xA1,0x80,0x00,0x8E,0xD8,0x90,0x3E,0x8A,0x07,0x08,0xD0,0x3E,0x88,0x07,0xF8,0x01,0xF3,0x49,0x83,0xF9,0x00,0x75,0xEE,0x5F,0x5E,0x5A,0x59,0x5B,0x58,0x07,0x1F";
	}else{
		*(c + 0)=VID+0x2000;
		*(c + 1)=x;
		*(c + 2)=y;
		*(c + 3)=40;
		*(c + 4)=x1;
		asm	"db 0x1E,0x06,0x50,0x53,0x51,0x52,0x56,0x57,0x2E,0xA1,0x86,0x00,0x89,0xC6,0x2E,0x8B,0x1E,0x82,0x00,0x2E,0x8B,0x0E,0x84,0x00,0x2E,0x8A,0x16,0x88,0x00,0x2E,0xA1,0x80,0x00,0x8E,0xD8,0xF6,0xD2,0x90,0x3E,0x8A,0x07,0x20,0xD0,0x3E,0x88,0x07,0xF8,0x01,0xF3,0x49,0x83,0xF9,0x00,0x75,0xEE,0x5F,0x5E,0x5A,0x59,0x5B,0x58,0x07,0x1F";
	}
	if((color & 8)!=0){
		*(c + 0)=VID+0x3000;
		*(c + 1)=x;
		*(c + 2)=y;
		*(c + 3)=40;
		*(c + 4)=x1;
		asm	"db 0x1E,0x06,0x50,0x53,0x51,0x52,0x56,0x57,0x2E,0xA1,0x86,0x00,0x89,0xC6,0x2E,0x8B,0x1E,0x82,0x00,0x2E,0x8B,0x0E,0x84,0x00,0x2E,0x8A,0x16,0x88,0x00,0x2E,0xA1,0x80,0x00,0x8E,0xD8,0x90,0x3E,0x8A,0x07,0x08,0xD0,0x3E,0x88,0x07,0xF8,0x01,0xF3,0x49,0x83,0xF9,0x00,0x75,0xEE,0x5F,0x5E,0x5A,0x59,0x5B,0x58,0x07,0x1F";
	}else{
		*(c + 0)=VID+0x3000;
		*(c + 1)=x;
		*(c + 2)=y;
		*(c + 3)=40;
		*(c + 4)=x1;
		asm	"db 0x1E,0x06,0x50,0x53,0x51,0x52,0x56,0x57,0x2E,0xA1,0x86,0x00,0x89,0xC6,0x2E,0x8B,0x1E,0x82,0x00,0x2E,0x8B,0x0E,0x84,0x00,0x2E,0x8A,0x16,0x88,0x00,0x2E,0xA1,0x80,0x00,0x8E,0xD8,0xF6,0xD2,0x90,0x3E,0x8A,0x07,0x20,0xD0,0x3E,0x88,0x07,0xF8,0x01,0xF3,0x49,0x83,0xF9,0x00,0x75,0xEE,0x5F,0x5E,0x5A,0x59,0x5B,0x58,0x07,0x1F";
	}


	
	
	ends:
	x=0;
}

void trig(x,y,size,color){
	int n;
	int ny=y;
	int nx=x;
	int nnx=2;
	for(n=0;n<size;n++){
		vline(nx-n/2,ny+n,nx-n/2,ny+n+1,color);
		vline(nx+n/2,ny+n,nx+n/2,ny+n+1,color);
	}
}


int getkey()
{
	int *c;
	c = (int * ) varn;

		asm	"db 0x1E,0x06,0x50,0x53,0x51,0x52,0x56,0x57,0xB4,0x01,0xCD,0x16,0x75,0x09,0xB8,0x00,0x00,0x2E,0xA3,0x80,0x00,0xEB,0x09,0x90,0xB4,0x00,0xCD,0x16,0x2E,0xA3,0x80,0x00,0x90,0x5F,0x5E,0x5A,0x59,0x5B,0x58,0x07,0x1F";
	return *(c + 0);	
}


void rxline(x,y,x1,y1,color)
int x;
int y;
int x1;
int y1;
{
	int n;
	int xx;
	int yy;
	int xxx;
	int yyy;
	int counter=0;
	if(x1>x && y1>y){
		xx=x1-x;
		yy=y1-y;
		yy=yy*100;
		yy=yy/xx;
		yyy=0;
		xxx=yy*xx/10;
		for(n=0;n<xx;n++){
				vline(x+n,y+yyy/100,1+x+n,1+y+yyy/100,color);
				yyy=yyy+yy;
		}
	}	
}


void lxline(x,y,x1,y1,color)
int x;
int y;
int x1;
int y1;
{
	int n;
	int xx;
	int yy;
	int xxx;
	int yyy;
	int counter=0;
	if(x1>x && y1<y){
		xx=x1-x;
		yy=y-y1;
		yy=yy*100;
		yy=yy/xx;
		yyy=0;
		xxx=yy*xx/10;
		for(n=0;n<xx;n++){
				vline(x+n,y+yyy/100,1+x+n,1+y+yyy/100,color);
				yyy=yyy-yy;
		}
	}	
}


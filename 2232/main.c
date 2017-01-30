#include<stdio.h>
#include <msp430g2231.h>

volatile int countra=0;
volatile char tempz[36];
char H[6]={0x37,0x04,0x04,0x04,0x37, 0x00};
char A[6]={0x07,0x012,0x22,0x12,0x07,0x00};
char P[6]={0x37,0x22,0x12,0x04, 0x00,0x00};
char Y[6]={0x20,0x10,0x7,0x10,0x20,0x00};
char D[6]={0x37,0x21,0x21,0x12,0x04,0x00};
char W[6]={0x36,0x01,0x02,0x01,0x36,0x00};
char L[6]={0x37,0x01,0x01,0x01,0x01,0x00};
char I[6]={0x21,0x21,0x37,0x21,0x21,0x00};
char oo[6]={0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
void printza(char inchar[], int pos);
void delay_cyclesm(unsigned int x);



void delay_cyclesm(unsigned int x)
{unsigned int i,k;
	do
	{i--;
	k=1000;
		do		 //P1OUT = 0x00;
		{
			k--;
		}while(k !=1);
	}while(i != 0);
}

void printza(char inchar[], int pos)
{

	switch(pos)
	    {
	    case 1: tempz[0]= inchar[0];
	    		tempz[1]= inchar[1];
	    		tempz[2]= inchar[2];
	    		tempz[3]= inchar[3];
	    		tempz[4]= inchar[4];
	    		tempz[5]= inchar[5];break;
	    case 2:		tempz[6]= inchar[0];
	        		tempz[7]= inchar[1];
	        		tempz[8]= inchar[2];
	        		tempz[9]= inchar[3];
	        		tempz[10]= inchar[4];
	        		tempz[11]= inchar[5];break;
	    case 3:		tempz[12]= inchar[0];
	        		tempz[13]= inchar[1];
	        		tempz[14]= inchar[2];
	        		tempz[15]= inchar[3];
	        		tempz[16]= inchar[4];
	        		tempz[17]= inchar[5];break;
	    case 4:		tempz[18]= inchar[0];
	        		tempz[19]= inchar[1];
	        		tempz[20]= inchar[2];
	        		tempz[21]= inchar[3];
	        		tempz[22]= inchar[4];
	        		tempz[23]= inchar[5];break;
	    case 5:		tempz[24]= inchar[0];
	    			tempz[25]= inchar[1];
	            	tempz[26]= inchar[2];
	            	tempz[27]= inchar[3];
	            	tempz[28]= inchar[4];
	            	tempz[29]= inchar[5];break;
	    case 6: 	tempz[30]= inchar[0];
					tempz[31]= inchar[1];
					tempz[32]= inchar[2];
					tempz[33]= inchar[3];
					tempz[34]= inchar[4];
					tempz[35]= inchar[5];break;
	    default:	tempz[0]=0x37;break;
	    }


}

int main(void)  //Main program
{
	char ttemp[]={0x37,0x04,0x04,0x04,0x37, 0x00,0x07,0x012,0x26,0x12,0x07,0x00,0x37,0x22,0x24,0x4, 0x00,0x00,0x37,0x22,0x24,0x4, 0x00,0x00, 0x20,0x10,0x7,0x10,0x20,0x00};
 WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer

 P1DIR |= 0x37; // Set P1.0 to output and P1.3 to input direction
 P1OUT &= ~BIT0; // set P1.0 to Off
 P1IE |= BIT3; // P1.3 interrupt enabled
 P1IFG &= ~BIT3; // P1.3 interrupt flag cleared

 CCTL0 = CCIE;                             // CCR0 interrupt enabled
 CCR0 = 4000;
 TACTL = TASSEL_2 + MC_2;                  // SMCLK, contmode
 __bis_SR_register(GIE); // Enable all interrupts

 // _BIS_SR(LPM0_bits + GIE);                 // Enter LPM0 w/ interrupt
    {
	  		  	  printza(D,1);
	  		  	  printza(I,2);
	  		  	  printza(W,3);
	  		  	  printza(A,4);
	  		  	  printza(L,5);
	  		  	  printza(I,6);
	  	  	  } 
 while(1)
  {

	  	 // if(uu<4000)

	  	 // if(uu>4000 && uu<8000)
	delay_cyclesm(20000);
	{
		  printza(D,1);
			  		  	  printza(I,2);
			  		  	  printza(W,3);
			  		  	  printza(A,4);
			  		  	  printza(L,5);
			  		  	  printza(I,6);
	}
	delay_cyclesm(20000);
	{
		 printza(H,1);
					  		  	  printza(A,2);
					  		  	  printza(P,3);
					  		  	  printza(P,4);
					  		  	  printza(Y,5);
					  		  	printza(oo,5);
	}
	delay_cyclesm(20000);
	{
		printza(oo,1);
		printza(oo,2);
		printza(oo,3);
		printza(oo,4);
		printza(oo,5);
		printza(oo,6);
	}
	

	  	  	


  }



//

 //Loop forever, we'll do our job in the interrupt routine... {


}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
    P1OUT = 0x00;  // Toggle P1.0
    delay_cyclesm(20000);
    P1IFG &= ~BIT3; // P1.3 interrupt flag cleared

}

#pragma vector=TIMERA0_VECTOR
__interrupt void Timer_A (void)
{//makeip();

	if(countra<150)
		{
		countra++;
                                        switch(countra)
	  	  			{
	  	  			case 1: P1OUT = tempz[0];break;
	  	  			case 3: P1OUT = tempz[1];break;
	  	  			case 5: P1OUT = tempz[2];break;
	  	  			case 7: P1OUT = tempz[3];break;
	  	  			case 9: P1OUT = tempz[4];break;
	  	  			case 11: P1OUT = tempz[5];break;
	  	  			case 13: P1OUT = tempz[6];break;
	  	  			case 15: P1OUT = tempz[7];break;
	  	  			case 17: P1OUT = tempz[8];break;
	  	  			case 19: P1OUT = tempz[9];break;
	  	  			case 21: P1OUT = tempz[10];	break;
	  	  			case 23: P1OUT = tempz[11];break;
	  	  			case 25: P1OUT = tempz[12];break;
	  	  			case 27: P1OUT = tempz[13];	break;
	  	  			case 29: P1OUT = tempz[14];break;
	  	  			case 31: P1OUT = tempz[15];break;
	  	  			case 33: P1OUT = tempz[16];break;
	  	  			case 35: P1OUT = tempz[17];break;
	  	  			case 37: P1OUT = tempz[18];break;
	  	  			case 39: P1OUT = tempz[19];break;
	  	  			case 41: P1OUT = tempz[20];break;
	  	  			case 43: P1OUT = tempz[21];break;
	  	  			case 45: P1OUT = tempz[22];break;
	  	  			case 47: P1OUT = tempz[23];break;
	  	  			case 49: P1OUT = tempz[24];break;
	  	  			case 51: P1OUT = tempz[25];break;
	  	  			case 53: P1OUT = tempz[26];break;
	  	  			case 55: P1OUT = tempz[27];break;
	  	  			case 57: P1OUT = tempz[28];break;
	  	  			case 59: P1OUT = tempz[29];break;
	  	  			case 61: P1OUT = tempz[30];break;
	  	  			case 63: P1OUT = tempz[31];break;
	  	  			case 65: P1OUT = tempz[32];break;
	  	  			case 67: P1OUT = tempz[33];break;
	  	  			case 69: P1OUT = tempz[34];break;
	  	  			case 71: P1OUT = tempz[35];break;
	  	  			default:P1OUT=0x00;break;
	  	  			}

		}
	else
		{countra=0;
		P1OUT = 0x00;
		//uu++;
		}
	
  //P1OUT ^= 0x41;                            // Toggle P1.0
  CCR0 += 700;                            // Add Offset to CCR0
}

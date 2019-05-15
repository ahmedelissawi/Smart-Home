
#define uint8_t unsigned char
	


uint8_t ADC_to_temp (int ADCval)
{
	
	//3.3v ADC range and ADCval is expected from 0 to 4095
	
	int tempval;
	tempval = 147.5-((75 * 3.3 *(ADCval))/4096);
		
	return tempval;
}
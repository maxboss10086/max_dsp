#include "driverlib.h"
#include "device.h"
//#include "F28x_Project.h"
#include "DLOG_4CH_F.h"

DLOG_4CH_F dlog_4ch;
//*********** Structure Init Function *****//
void DLOG_4CH_F_init(DLOG_4CH_F *v)
{
	v->input_ptr1 = 0;
	v->input_ptr2 = 0;
	v->input_ptr3 = 0;
	v->input_ptr4 = 0;
	v->output_ptr1= 0;
	v->output_ptr2= 0;
	v->output_ptr3= 0;
	v->output_ptr4= 0;
	v->prev_value = 0;
	v->trig_value = 0;
	v->status= 0;
	v->pre_scalar = 0;
	v->skip_count = 0;
	v->size = 0;
	v->count = 0;
}
void DLOG_init(DLOG_4CH_F *v){
    DLOG_4CH_F_init(&dlog_4ch);
    v->input_ptr1 = &v->DlogCh1;    //data value
    v->input_ptr2 = &v->DlogCh2;
    v->input_ptr3 = &v->DlogCh3;
    v->input_ptr4 = &v->DlogCh4;
    v->output_ptr1 = &v->DBUFF_4CH1[0];
    v->output_ptr2 = &v->DBUFF_4CH2[0];
    v->output_ptr3 = &v->DBUFF_4CH3[0];
    v->output_ptr4 = &v->DBUFF_4CH4[0];
    v->size = 200;
    v->pre_scalar = 5;
    v->trig_value = 0.5;//设置通道1的触发信号，其他通道会相应显示
    v->status = 2;
}


//*********** Function Definition ********//
void DLOG_4CH_F_FUNC(DLOG_4CH_F *v)
{
	switch(v->status)
	{
	case 1: /* wait for trigger*/
		if(*v->input_ptr1>v->trig_value && v->prev_value<v->trig_value)
		{
			/* rising edge detected start logging data*/
			v->status=2;
		}
		break;
	case 2:
		v->skip_count++;
		if(v->skip_count==v->pre_scalar)
		{
			v->skip_count=0;
			v->output_ptr1[v->count]=*v->input_ptr1;
			v->output_ptr2[v->count]=*v->input_ptr2;
			v->output_ptr3[v->count]=*v->input_ptr3;
			v->output_ptr4[v->count]=*v->input_ptr4;
			v->count++;
			if(v->count==v->size)
			{
				v->count=0;
				v->status=1;
			}
		}
		break;
	}
	v->prev_value=*v->input_ptr1;
}


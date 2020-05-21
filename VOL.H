
/*
#define proc10  (0.100)
#define proc85  (0.850)
#define proc90  (0.900)
*/
extern float proc10;
extern float proc85;
extern float proc90;

extern int num_out1,num_out2,num_out3;
//#define OUT1 msk_int[num_out1]
//#define OUT2 msk_int[num_out2]

#define OUT1 (0x2000)
#define OUT2 (0x4000)
#define OUT3 (0x8000)

#define  bit_10p  (0x2000)
#define  bit_90p  (0x4000)
#define  bit_85p  (0x8000)

//#define OUT3 msk_int[num_out3]

#define max_TCT  2000
#define max_ord  2048

#define seg_TCT (0xb000)

#define max_nn   3

#define MM_LVL (50000)
#define cyl_nn   10

struct s_TCT
{
float level;
float volume;
};

struct s_Cyl
{
 float Radius;
 float Radius1;
 float Lgth;
 float Offs;    // расстояние от базы TCT (Level=0) до оси цилиндра
};

extern struct s_Cyl Vol1[];
extern struct s_Cyl Vol2[];
extern struct s_Cyl Vol3[];

extern struct s_Cyl *Cyl_ARR[];
extern struct s_TCT *TCT_T1;
extern struct s_TCT *TCT_T2;
extern struct s_TCT *TCT_T3;
extern struct s_TCT *TCT_ARR[];
extern int n_TCT[];

extern struct s_TCT TCT_sz;

float f_get_vol(int ii);
double f_vol_cyl(double h, double Rr, double Ll);
float f_get_volD(int ii);

int  f_wr_tct();
void  f_rd_tct();

extern float (*ff_get_vol[max_nn])(int ii);

extern int flag_vol[];
extern int flag_maxV[];
extern float Vol_max[];

extern float *val_Temp[];
extern float *val_Press[];
extern float D_Etan100,D_Etan,P_Etan;
extern int n_Cyl[];

void f_count_tank(int ii);

extern float Vol_10[];
extern float Vol_85[];
extern float Vol_90[];

extern float H_Cyl_M[];

void f_prep_VM(int ii);

double f_vol_cyl(double h, double Rr, double Ll);
double f_vol_cyl12 (double Level,struct s_Cyl *Cyl_str_ptr);

extern float alpha_LVL[]  ;
extern float alpha_Tank[] ;
extern float T0_LVL[] ;
extern float T0_Tank[];


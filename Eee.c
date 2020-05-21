
char buf_eep[max_buf_eep];
int eee_num=0;
unsigned long int Eeprom_summ;
unsigned int ee_lgth_byte=0;
float fict_ftmp=0;
int fict_itmp=0;
int fict_sv=0;
int fict_int1=1;


// Список параметров сохраняемых в EEPROM
struct eee_dat EE_Dat[]=
{
&ComBaud[0],sizeof(ComBaud[0]),
&ComBaud[1],sizeof(ComBaud[1]),
&ComBaud[2],sizeof(ComBaud[2]),
&ComBaud[3],sizeof(ComBaud[3]),
&ComBaud[4],sizeof(ComBaud[4]),

&eee_num,sizeof(eee_num),

#if defined(ICP_7017C)
//#if (0)    //defined(ICP_7017C)

&I7017C[0].status         ,sizeof(I7017C[0].status        ),
&I7017C[0].port           ,sizeof(I7017C[0].port          ),
&I7017C[0].addr           ,sizeof(I7017C[0].addr          ),
&I7017C[0].type           ,sizeof(I7017C[0].type          ),
&I7017C[0].format         ,sizeof(I7017C[0].format        ),
&I7017C[0].channels       ,sizeof(I7017C[0].channels      ),
&I7017C[0].CRC_flag       ,sizeof(I7017C[0].CRC_flag      ),
&I7017C[0].pool_time      ,sizeof(I7017C[0].pool_time     ),
&I7017_Rqst[0].timeout    ,sizeof(I7017_Rqst[0].timeout   ),

&I7017C[1].status         ,sizeof(I7017C[1].status        ),
&I7017C[1].port           ,sizeof(I7017C[1].port          ),
&I7017C[1].addr           ,sizeof(I7017C[1].addr          ),
&I7017C[1].type           ,sizeof(I7017C[1].type          ),
&I7017C[1].format         ,sizeof(I7017C[1].format        ),
&I7017C[1].channels       ,sizeof(I7017C[1].channels      ),
&I7017C[1].CRC_flag       ,sizeof(I7017C[1].CRC_flag      ),
&I7017C[1].pool_time      ,sizeof(I7017C[1].pool_time     ),
&I7017_Rqst[1].timeout    ,sizeof(I7017_Rqst[1].timeout   ),
#else

&ICP_fict.status         ,sizeof(ICP_fict.status        ),
&ICP_fict.port           ,sizeof(ICP_fict.port          ),
&ICP_fict.addr           ,sizeof(ICP_fict.addr          ),
&ICP_fict.type           ,sizeof(ICP_fict.type          ),
&ICP_fict.format         ,sizeof(ICP_fict.format        ),
&ICP_fict.channels       ,sizeof(ICP_fict.channels      ),
&ICP_fict.CRC_flag       ,sizeof(ICP_fict.CRC_flag      ),
&ICP_fict.pool_time      ,sizeof(ICP_fict.pool_time     ),
&Rqst_fict.timeout    ,sizeof(Rqst_fict.timeout    ),

&ICP_fict.status         ,sizeof(ICP_fict.status        ),
&ICP_fict.port           ,sizeof(ICP_fict.port          ),
&ICP_fict.addr           ,sizeof(ICP_fict.addr          ),
&ICP_fict.type           ,sizeof(ICP_fict.type          ),
&ICP_fict.format         ,sizeof(ICP_fict.format        ),
&ICP_fict.channels       ,sizeof(ICP_fict.channels      ),
&ICP_fict.CRC_flag       ,sizeof(ICP_fict.CRC_flag      ),
&ICP_fict.pool_time      ,sizeof(ICP_fict.pool_time     ),
&Rqst_fict.timeout    ,sizeof(Rqst_fict.timeout   ),

#endif

&ComPortEcho          ,sizeof(ComPortEcho        ),
&ToutLicpScan         ,sizeof(ToutLicpScan       ),
&licp_amax            ,sizeof(licp_amax          ),
&LICP_Rqst.CRC_flag   ,sizeof(LICP_Rqst.CRC_flag ),

#if defined(ICP_7060)

&I7060[0].status         ,sizeof(I7060[0].status        ),
&I7060[0].port           ,sizeof(I7060[0].port          ),
&I7060[0].addr           ,sizeof(I7060[0].addr          ),
&I7060[0].type           ,sizeof(I7060[0].type          ),
&I7060[0].format         ,sizeof(I7060[0].format        ),
&I7060[0].channels       ,sizeof(I7060[0].channels      ),
&I7060[0].CRC_flag       ,sizeof(I7060[0].CRC_flag      ),
&I7060[0].pool_time      ,sizeof(I7060[0].pool_time     ),
&I7060_Rqst[0].timeout    ,sizeof(I7060_Rqst[0].timeout   ),

&I7060[1].status         ,sizeof(I7060[1].status        ),
&I7060[1].port           ,sizeof(I7060[1].port          ),
&I7060[1].addr           ,sizeof(I7060[1].addr          ),
&I7060[1].type           ,sizeof(I7060[1].type          ),
&I7060[1].format         ,sizeof(I7060[1].format        ),
&I7060[1].channels       ,sizeof(I7060[1].channels      ),
&I7060[1].CRC_flag       ,sizeof(I7060[1].CRC_flag      ),
&I7060[1].pool_time      ,sizeof(I7060[1].pool_time     ),
&I7060_Rqst[1].timeout    ,sizeof(I7060_Rqst[1].timeout   ),
#else

&ICP_fict.status         ,sizeof(ICP_fict.status        ),
&ICP_fict.port           ,sizeof(ICP_fict.port          ),
&ICP_fict.addr           ,sizeof(ICP_fict.addr          ),
&ICP_fict.type           ,sizeof(ICP_fict.type          ),
&ICP_fict.format         ,sizeof(ICP_fict.format        ),
&ICP_fict.channels       ,sizeof(ICP_fict.channels      ),
&ICP_fict.CRC_flag       ,sizeof(ICP_fict.CRC_flag      ),
&ICP_fict.pool_time      ,sizeof(ICP_fict.pool_time     ),
&Rqst_fict.timeout       ,sizeof(Rqst_fict.timeout    ),

&ICP_fict.status         ,sizeof(ICP_fict.status        ),
&ICP_fict.port           ,sizeof(ICP_fict.port          ),
&ICP_fict.addr           ,sizeof(ICP_fict.addr          ),
&ICP_fict.type           ,sizeof(ICP_fict.type          ),
&ICP_fict.format         ,sizeof(ICP_fict.format        ),
&ICP_fict.channels       ,sizeof(ICP_fict.channels      ),
&ICP_fict.CRC_flag       ,sizeof(ICP_fict.CRC_flag      ),
&ICP_fict.pool_time      ,sizeof(ICP_fict.pool_time     ),
&Rqst_fict.timeout       ,sizeof(Rqst_fict.timeout    ),

#endif

&WDOG[0].status         ,sizeof( WDOG[0].status        ),
&WDOG[0].port           ,sizeof( WDOG[0].port          ),
&WDOG[0].CRC_flag       ,sizeof( WDOG[0].CRC_flag      ),
&WDOG[0].pool_time      ,sizeof( WDOG[0].pool_time     ),
&WDOG_Rqst[0].timeout   ,sizeof( WDOG_Rqst[0].timeout   ),

&WDOG[1].status         ,sizeof( WDOG[0].status        ),
&WDOG[1].port           ,sizeof( WDOG[0].port          ),
&WDOG[1].CRC_flag       ,sizeof( WDOG[0].CRC_flag      ),
&WDOG[1].pool_time      ,sizeof( WDOG[0].pool_time     ),
&WDOG_Rqst[1].timeout   ,sizeof( WDOG_Rqst[0].timeout   ),

&ComProt[0]     ,sizeof( ComProt[0] ),
&ComProt[1]     ,sizeof( ComProt[1] ),
&ComProt[2]     ,sizeof( ComProt[2] ),
&ComProt[3]     ,sizeof( ComProt[3] ),
&ComProt[4]     ,sizeof( ComProt[4] ),


#if defined(RTU_ComSK)

&ComSK[0].status         ,sizeof(ComSK[0].status        ),
&ComSK[0].port           ,sizeof(ComSK[0].port          ),
&ComSK[0].addr           ,sizeof(ComSK[0].addr          ),
&ComSK[0].pool_time      ,sizeof(ComSK[0].pool_time     ),
&ComSK_Rqst[0].timeout   ,sizeof(ComSK_Rqst[0].timeout   ),
&ComSK_WD_Rqst[0].timeout, sizeof(ComSK_WD_Rqst[0].timeout),
&sk_pool_period[0] ,sizeof(sk_pool_period[0]),

&ComSK[1].status         ,sizeof(ComSK[1].status        ),
&ComSK[1].port           ,sizeof(ComSK[1].port          ),
&ComSK[1].addr           ,sizeof(ComSK[1].addr          ),
&ComSK[1].pool_time      ,sizeof(ComSK[1].pool_time     ),
&ComSK_Rqst[1].timeout   ,sizeof(ComSK_Rqst[1].timeout   ),
&ComSK_WD_Rqst[1].timeout, sizeof(ComSK_WD_Rqst[1].timeout),
&sk_pool_period[1] ,sizeof(sk_pool_period[1]),

#else

&ICP_fict.status         ,sizeof(ICP_fict.status        ),
&ICP_fict.port           ,sizeof(ICP_fict.port          ),
&ICP_fict.addr           ,sizeof(ICP_fict.addr          ),
&ICP_fict.pool_time      ,sizeof(ICP_fict.pool_time     ),
&Rqst_fict.timeout    ,sizeof(Rqst_fict.timeout   ),
&fict_long                ,sizeof(fict_long),
&fict_long                ,sizeof(fict_long),

&ICP_fict.status         ,sizeof(ICP_fict.status        ),
&ICP_fict.port           ,sizeof(ICP_fict.port          ),
&ICP_fict.addr           ,sizeof(ICP_fict.addr          ),
&ICP_fict.pool_time      ,sizeof(ICP_fict.pool_time     ),
&Rqst_fict.timeout    ,sizeof(Rqst_fict.timeout   ),
&fict_long            ,sizeof(fict_long),
&fict_long            ,sizeof(fict_long),
#endif

#if defined(RTU_Delta)

&Delta[0].status         ,sizeof(Delta[0].status        ),
&Delta[0].port           ,sizeof(Delta[0].port          ),
&Delta[0].addr           ,sizeof(Delta[0].addr          ),
&Delta[0].pool_time      ,sizeof(Delta[0].pool_time     ),
&Delta_Rqst[0].timeout   ,sizeof(Delta_Rqst[0].timeout   ),
&fict_long                ,sizeof(fict_long),
&fict_long                ,sizeof(fict_long),
//&Delta_WD_Rqst[0].timeout, sizeof(Delta_WD_Rqst[0].timeout),
//&Dlt_pool_period[0] ,sizeof(sk_pool_period[0]),

&Delta[1].status         ,sizeof(Delta[1].status        ),
&Delta[1].port           ,sizeof(Delta[1].port          ),
&Delta[1].addr           ,sizeof(Delta[1].addr          ),
&Delta[1].pool_time      ,sizeof(Delta[1].pool_time     ),
&Delta_Rqst[1].timeout   ,sizeof(Delta_Rqst[1].timeout   ),
&fict_long                ,sizeof(fict_long),
&fict_long                ,sizeof(fict_long),
//&Delta_WD_Rqst[1].timeout, sizeof(Delta_WD_Rqst[1].timeout),
//&Dlt_pool_period[1] ,sizeof(sk_pool_period[1]),

#else

&ICP_fict.status         ,sizeof(ICP_fict.status        ),
&ICP_fict.port           ,sizeof(ICP_fict.port          ),
&ICP_fict.addr           ,sizeof(ICP_fict.addr          ),
&ICP_fict.pool_time      ,sizeof(ICP_fict.pool_time     ),
&Rqst_fict.timeout    ,sizeof(Rqst_fict.timeout   ),
&fict_long                ,sizeof(fict_long),
&fict_long                ,sizeof(fict_long),

&ICP_fict.status         ,sizeof(ICP_fict.status        ),
&ICP_fict.port           ,sizeof(ICP_fict.port          ),
&ICP_fict.addr           ,sizeof(ICP_fict.addr          ),
&ICP_fict.pool_time      ,sizeof(ICP_fict.pool_time     ),
&Rqst_fict.timeout    ,sizeof(Rqst_fict.timeout   ),
&fict_long            ,sizeof(fict_long),
&fict_long            ,sizeof(fict_long),

#endif
//-----------------------

&Com_lgth[0]   ,sizeof(Com_lgth[0]),
&Com_lgth[1]   ,sizeof(Com_lgth[0]),
&Com_lgth[2]   ,sizeof(Com_lgth[0]),
&Com_lgth[3]   ,sizeof(Com_lgth[0]),
&Com_lgth[4]   ,sizeof(Com_lgth[0]),
&Com_parity[0],sizeof(Com_parity[0]),
&Com_parity[1],sizeof(Com_parity[0]),
&Com_parity[2],sizeof(Com_parity[0]),
&Com_parity[3],sizeof(Com_parity[0]),
&Com_parity[4],sizeof(Com_parity[0]),
&Com_stop[0]  ,sizeof(Com_stop[0]),
&Com_stop[1]  ,sizeof(Com_stop[0]),
&Com_stop[2]  ,sizeof(Com_stop[0]),
&Com_stop[3]  ,sizeof(Com_stop[0]),
&Com_stop[4]  ,sizeof(Com_stop[0]),

//-----------------------
#if defined(RTU_MVD)

&MVD[0].status         ,sizeof(MVD[0].status        ),
&MVD[0].port           ,sizeof(MVD[0].port          ),
&MVD[0].addr           ,sizeof(MVD[0].addr          ),
&MVD[0].pool_time      ,sizeof(MVD[0].pool_time     ),
&MVD_Rqst[0].timeout   ,sizeof(MVD_Rqst[0].timeout   ),

&MVD[1].status         ,sizeof(MVD[1].status        ),
&MVD[1].port           ,sizeof(MVD[1].port          ),
&MVD[1].addr           ,sizeof(MVD[1].addr          ),
&MVD[1].pool_time      ,sizeof(MVD[1].pool_time     ),
&MVD_Rqst[1].timeout   ,sizeof(MVD_Rqst[1].timeout   ),

#else

&ICP_fict.status         ,sizeof(ICP_fict.status        ),
&ICP_fict.port           ,sizeof(ICP_fict.port          ),
&ICP_fict.addr           ,sizeof(ICP_fict.addr          ),
&ICP_fict.pool_time      ,sizeof(ICP_fict.pool_time     ),
&Rqst_fict.timeout    ,sizeof(Rqst_fict.timeout   ),

&ICP_fict.status         ,sizeof(ICP_fict.status        ),
&ICP_fict.port           ,sizeof(ICP_fict.port          ),
&ICP_fict.addr           ,sizeof(ICP_fict.addr          ),
&ICP_fict.pool_time      ,sizeof(ICP_fict.pool_time     ),
&Rqst_fict.timeout    ,sizeof(Rqst_fict.timeout   ),

#endif
//-----------------------
#if defined(ICP_TSD)

&TSD[0].status         ,sizeof(TSD[0].status        ),
&TSD[0].port           ,sizeof(TSD[0].port          ),
&TSD[0].addr           ,sizeof(TSD[0].addr          ),
&TSD[0].pool_time      ,sizeof(TSD[0].pool_time     ),
&TSD_Rqst[0].timeout   ,sizeof(TSD_Rqst[0].timeout   ),

&TSD[1].status         ,sizeof(TSD[1].status        ),
&TSD[1].port           ,sizeof(TSD[1].port          ),
&TSD[1].addr           ,sizeof(TSD[1].addr          ),
&TSD[1].pool_time      ,sizeof(TSD[1].pool_time     ),
&TSD_Rqst[1].timeout   ,sizeof(TSD_Rqst[1].timeout   ),

#else

&ICP_fict.status         ,sizeof(ICP_fict.status        ),
&ICP_fict.port           ,sizeof(ICP_fict.port          ),
&ICP_fict.addr           ,sizeof(ICP_fict.addr          ),
&ICP_fict.pool_time      ,sizeof(ICP_fict.pool_time     ),
&Rqst_fict.timeout    ,sizeof(Rqst_fict.timeout   ),

&ICP_fict.status         ,sizeof(ICP_fict.status        ),
&ICP_fict.port           ,sizeof(ICP_fict.port          ),
&ICP_fict.addr           ,sizeof(ICP_fict.addr          ),
&ICP_fict.pool_time      ,sizeof(ICP_fict.pool_time     ),
&Rqst_fict.timeout    ,sizeof(Rqst_fict.timeout   ),

#endif

//-----------------------

&byte_timout_rtu[0]   ,sizeof(byte_timout_rtu),
&scom_tim[0]   ,sizeof(scom_tim),

&ahour00.hour ,sizeof(ahour00.hour),
&ahour00.min  ,sizeof(ahour00.min),
&ahour00.sec  ,sizeof(ahour00.sec),

//-----------------------
&ComBaudSlv     ,sizeof(ComBaudSlv    ),
&Com_lgthSlv    ,sizeof(Com_lgthSlv   ),
&Com_paritySlv  ,sizeof(Com_paritySlv ),
&Com_stopSlv    ,sizeof(Com_stopSlv   ),
//-----------------------
&ComPortSlv ,sizeof(ComPortSlv ),
&AddrSlv    ,sizeof(AddrSlv  ),
&fict_itmp   ,sizeof(fict_itmp  ),
//-----------------------
&flag_Slv  ,sizeof(flag_Slv ),

&FlagWinSum ,sizeof(FlagWinSum ),

&f_ns[0]        ,sizeof(f_ns[0]        ),
&f_ns[1]        ,sizeof(f_ns[1]        ),
&f_ns[2]        ,sizeof(f_ns[2]        ),
&f_ns[3]        ,sizeof(f_ns[3]        ),
&f_ns[4]        ,sizeof(f_ns[4]        ),
&i_nn_d         ,sizeof(i_nn_d         ),
&dim_xyz        ,sizeof(dim_xyz        ),
&fl_trace_loop  ,sizeof(fl_trace_loop  ),

//-----------------------
&fict_ftmp      ,sizeof(fict_ftmp      ),
&fict_ftmp      ,sizeof(fict_ftmp      ),
&fict_ftmp      ,sizeof(fict_ftmp      ),
&fict_ftmp      ,sizeof(fict_ftmp      ),
&fict_itmp      ,sizeof(fict_itmp      ),
&fict_ftmp      ,sizeof(fict_ftmp      ),


&fict_long ,sizeof(fict_long  ),

&v_num_var                ,sizeof( v_num_var                ),

&fl_id1  ,sizeof( fl_id1),
&chr_id[0] ,sizeof( chr_id),
&fl_id  ,sizeof( fl_id),
//--------------
&fict_int1  ,sizeof(fict_int1 ),

&WD_PMP_Per  ,sizeof(WD_PMP_Per ),
&n_id        ,sizeof(n_id ),

/*
&Ekd.status         ,sizeof(Ekd.status        ),
&Ekd.port           ,sizeof(Ekd.port          ),
&Ekd.pool_time      ,sizeof(Ekd.pool_time     ),
&Ekd_Rqst.timeout   ,sizeof(Ekd_Rqst.timeout   ),
*/

&DGM[0].status         ,sizeof(DGM[0].status      ),
&DGM[0].port           ,sizeof(DGM[0].port        ),
&DGM[0].pool_time      ,sizeof(DGM[0].pool_time   ),
&DGM_Rqst[0].timeout   ,sizeof(DGM_Rqst[0].timeout),

&DGM[1].status         ,sizeof(DGM[1].status      ),
&DGM[1].port           ,sizeof(DGM[1].port        ),
&DGM[1].pool_time      ,sizeof(DGM[1].pool_time   ),
&DGM_Rqst[1].timeout   ,sizeof(DGM_Rqst[1].timeout),

&DGM_ADDR[0],      sizeof( DGM_ADDR[0]   ),
&DGM_ADDR[1],      sizeof( DGM_ADDR[1]   ),

//-----------------------
&ComBaudSlv2    ,sizeof(ComBaudSlv2   ),
&Com_lgthSlv2   ,sizeof(Com_lgthSlv2  ),
&Com_paritySlv2 ,sizeof(Com_paritySlv2),
&Com_stopSlv2   ,sizeof(Com_stopSlv2  ),
//-----------------------
&ComPortSlv2,sizeof(ComPortSlv2),
&AddrSlv2   ,sizeof(AddrSlv2 ),
&flag_Slv2 ,sizeof(flag_Slv2),
//-----------------------

&Vol1[0] ,sizeof(Vol1[0]),
&Vol1[1] ,sizeof(Vol1[0]),
&Vol1[2] ,sizeof(Vol1[0]),
&Vol1[3] ,sizeof(Vol1[0]),
&Vol1[4] ,sizeof(Vol1[0]),
&Vol1[5] ,sizeof(Vol1[0]),
&Vol1[6] ,sizeof(Vol1[0]),
&Vol1[7] ,sizeof(Vol1[0]),
&Vol1[8] ,sizeof(Vol1[0]),
&Vol1[9] ,sizeof(Vol1[0]),

&Vol2[0] ,sizeof(Vol2[0]),
&Vol2[1] ,sizeof(Vol2[0]),
&Vol2[2] ,sizeof(Vol2[0]),
&Vol2[3] ,sizeof(Vol2[0]),
&Vol2[4] ,sizeof(Vol2[0]),
&Vol2[5] ,sizeof(Vol2[0]),
&Vol2[6] ,sizeof(Vol2[0]),
&Vol2[7] ,sizeof(Vol2[0]),
&Vol2[8] ,sizeof(Vol2[0]),
&Vol2[9] ,sizeof(Vol2[0]),

&flag_vol[0],  sizeof(flag_vol[0]),
&flag_vol[1],  sizeof(flag_vol[1]),

&s_DGM[0].offset    ,  sizeof(s_DGM[0].offset       ),
&s_DGM[1].offset    ,  sizeof(s_DGM[1].offset       ),
&s_DGM[0].scale   ,  sizeof(s_DGM[0].scale   ),
&s_DGM[1].scale   ,  sizeof(s_DGM[1].scale   ),

&num_out1, sizeof( num_out1 ),
&num_out2, sizeof( num_out2 ),

&alpha_LVL[0] , sizeof( alpha_LVL[0]  ),
&alpha_LVL[1] , sizeof( alpha_LVL[1]  ),
&T0_LVL[0]    , sizeof( T0_LVL[0]     ),
&T0_LVL[1]    , sizeof( T0_LVL[1]     ),
&alpha_Tank[0], sizeof( alpha_Tank[0] ),
&alpha_Tank[1], sizeof( alpha_Tank[1] ),
&T0_Tank[0]   , sizeof( T0_Tank[0]    ),
&T0_Tank[1]   , sizeof( T0_Tank[1]    ),

//---------------------------
&DGM[2].status         ,sizeof(DGM[1].status      ),
&DGM[2].port           ,sizeof(DGM[1].port        ),
&DGM[2].pool_time      ,sizeof(DGM[1].pool_time   ),
&DGM_Rqst[2].timeout   ,sizeof(DGM_Rqst[1].timeout),

&DGM_ADDR[2],      sizeof( DGM_ADDR[0]   ),

//-----------------------
&ComBaudSlv3    ,sizeof(ComBaudSlv2   ),
&Com_lgthSlv3   ,sizeof(Com_lgthSlv2  ),
&Com_paritySlv3 ,sizeof(Com_paritySlv2),
&Com_stopSlv3   ,sizeof(Com_stopSlv2  ),
//-----------------------
&ComPortSlv3,sizeof(ComPortSlv2),
&AddrSlv3   ,sizeof(AddrSlv2 ),
&flag_Slv3 ,sizeof(flag_Slv2),
//-----------------------

&Vol3[0] ,sizeof(Vol1[0]),
&Vol3[1] ,sizeof(Vol1[0]),
&Vol3[2] ,sizeof(Vol1[0]),
&Vol3[3] ,sizeof(Vol1[0]),
&Vol3[4] ,sizeof(Vol1[0]),
&Vol3[5] ,sizeof(Vol1[0]),
&Vol3[6] ,sizeof(Vol1[0]),
&Vol3[7] ,sizeof(Vol1[0]),
&Vol3[8] ,sizeof(Vol1[0]),
&Vol3[9] ,sizeof(Vol1[0]),

&flag_vol[2],  sizeof(flag_vol[1]),

&s_DGM[2].offset    ,  sizeof(s_DGM[0].offset       ),
&s_DGM[2].scale   ,  sizeof(s_DGM[0].scale   ),

&alpha_LVL[2] , sizeof( alpha_LVL[0]  ),
&T0_LVL[2]    , sizeof( T0_LVL[0]     ),
&alpha_Tank[2], sizeof( alpha_Tank[0] ),
&T0_Tank[2]   , sizeof( T0_Tank[0]    ),


&H_Cyl_M[0], sizeof(H_Cyl_M[0]  ),
&H_Cyl_M[1], sizeof(H_Cyl_M[1]  ),
&H_Cyl_M[2], sizeof(H_Cyl_M[2]  ),

&byte_timout_slv    ,sizeof( byte_timout_slv  ),
&out_delay_slv      ,sizeof( out_delay_slv    ),

//&num_out3, sizeof( num_out3 ),
&proc10,  sizeof (proc10),
&proc85, sizeof (proc85),
&proc90, sizeof (proc90),

&Eeprom_summ,sizeof(Eeprom_summ),

NULL,0,
};
//---------------------------
void f_ee_num_init()
{
int i;
   for( i=0;EE_Dat[i].ptr != 0;i++) {}
   eee_num=i;
}
//---------------------------
int ee_members=0;
int f_wrt_eee()
/* Store all variables in EEE  */
{
int i,i1,i2,j;
int val;
char *ch_ptr;

 Eeprom_summ=0;

        for(i=0,i1=0;EE_Dat[i].ptr!=0;i++)
        {
          i2=EE_Dat[i].l;
          ch_ptr=(char *)EE_Dat[i].ptr;
          for(j=0;j<i2;j++)
          {
            buf_eep[i1]=*ch_ptr++;
            if(EE_Dat[i].ptr!= &Eeprom_summ)
//              Eeprom_summ +=buf_eep[i1];
              Eeprom_summ +=((unsigned long)(buf_eep[i1])) & 0xff;
            i1++;
          }
        }

          i2=EE_Dat[i].l;
          ch_ptr=(char *)EE_Dat[i].ptr;

 EE_WriteEnable();
   i2= EE_MultiWrite_L(0,i1,buf_eep);
 EE_WriteProtect();

    ee_members=i;

// printf (" %d",i);
 return i2;
}
//--------------------------------------
int f_chk_EEE_CRC()
{
int i,i1,i2,j;
int val;
char *ch_ptr;
unsigned long int Ee_summ;

 Ee_summ=0;

 if((i1=EE_MultiRead_L(0,2048,buf_eep))<0 )
 {
   return i1;
 }
//-----------------------------
   // Check CRC
        for(i=0,i1=0;EE_Dat[i].ptr!=0;i++)
        {
          i2=EE_Dat[i].l;
          ch_ptr=(char *)EE_Dat[i].ptr;
          for(j=0;j<i2;j++)
          {
            if(EE_Dat[i].ptr==&Eeprom_summ)
              *ch_ptr++=buf_eep[i1++];
            else
              Ee_summ +=((unsigned long)(buf_eep[i1++])) & 0xff;
          }
        }

     ee_lgth_byte=i1;
//  printf("\n\rf_chk_EEE_CRC: %d записей,%dбайт,CRC_count=%08lx,CRC_rd%08lx\n\r",i,i1,Ee_summ,Eeprom_summ);
   if(Ee_summ != Eeprom_summ) return -100;
   return 0;
}
//--------------------------------------
int f_rd_eee()
/* Read all variables from  buf_eep  */
{
int i,i1,i2,j;
int val;
char *ch_ptr;

unsigned long int Ee_summ;
 Ee_summ=0;
//-----------------------------

   for(i=0,i1=0;(EE_Dat[i].ptr!=0)&&(i<(eee_num-1)) ;i++)
   {
     i2=EE_Dat[i].l;
     ch_ptr=(char *)EE_Dat[i].ptr;
     for(j=0;j<i2;j++)
     {
       *ch_ptr++=buf_eep[i1];
       Ee_summ +=buf_eep[i1++];
     }
   }
   f_ee_num_init();
   if(dim_xyz>=dim_xyz_c) dim_xyz=dim_xyz_c-6;


   DGM[0].addr=(int)DGM_ADDR[0];
   DGM[1].addr=(int)DGM_ADDR[1];
   DGM[2].addr=(int)DGM_ADDR[2];
    return 0;
}
//--------------------------------------


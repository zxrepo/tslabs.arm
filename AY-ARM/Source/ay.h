
// Internal register definition file
//
// (c) 2012, TS-Labs inc.
// All rights fucked out
//
// A lány még mindig nagyon szép, de hol van már a vágy?


#ifndef __AY_H
#define __AY_H


#include "types.h"


// --- Structures definition -----
// to do: align this to be power of 2
typedef struct {	//registers re-ordered to match memory alignment
	U32		sd_ns;		// Seed for Noise Generator
	W16		TF0;		// AY Reg #00, #01 - Tone frequency for CH0
	W16		TF1;		// AY Reg #02, #03 - Tone frequency for CH1
	W16		TF2;		// AY Reg #04, #05 - Tone frequency for CH2
	W16		EP;			// AY Reg #0B, #0C - Envelope period
	U16		ctr_tn0;	// Tone Generator Counter0
	U16		ctr_tn1;	// Tone Generator Counter1
	U16		ctr_tn2;	// Tone Generator Counter2
	U16		ctr_ev; 	// Envelope Period Counter
	U8		NF;			// AY Reg #06 - Noise frequency
	U8		MX;			// AY Reg #07 - Channels mux, I/O mode
	U8		V0;			// AY Reg #08 - Volume for CH0
	U8		V1;			// AY Reg #09 - Volume for CH1
	U8		V2;			// AY Reg #0A - Volume for CH2
	U8		EC;			// AY Reg #0D - Envelope control
	U8		IOA;		// AY Reg #0E - I/O port A
	U8		IOB;		// AY Reg #0F - I/O port B
	U8		ctr_ns;		// Noise Generator Counter
	U8		ph_ev;		// Phase of Envelope (00 - down, 01 - up, 10 - fall, 11 - rise)
	U8		vol_ev;		// Current Volume Level of Envelope
	U8		vol_0l;		// Channel A Volume Left
	U8		vol_0r;		// Channel A Volume Right
	U8		vol_1l;		// Channel B Volume Left
	U8		vol_1r;		// Channel B Volume Right
	U8		vol_2l;		// Channel C Volume Left
	U8		vol_2r;		// Channel C Volume Right
	S8		ph_tn0;		// Phase for Tone Generator0 (0 - off, 1 - on)
	S8		ph_tn1;		// Phase for Tone Generator1 (0 - off, 1 - on)
	S8		ph_tn2;		// Phase for Tone Generator2 (0 - off, 1 - on)
	U8		padding[22];
} AY_Regs;		//--- AY Registers and Variables-----


// --- Functions prototypes -----
void AY_Init(void);
void AY_Tick(void);
void AY_Tick_tone(int n);
void AY_Tick_noise(int n);
void AY_Tick_env(int n);


#endif /* __AY_H */


/*
 * control.c
 *
 *  Created on: Jun 11, 2021
 *      Author: adam
 */
#include "control.h"


void PhaseLeadController_Init(PhaseLeadController *ctr)
{
	//y = 4.731729441332686 x[n] + -4.526505912318582x[n-1] + 0.7947764709858962y[n-1]
	ctr->x_coeff[1] = -2.946632;
	ctr->y_coef = -2.946632;

	ctr->x[0] = 0.0;
	ctr->x[1] = 0.0;
	ctr->y[0] = 0.0;
	ctr->y[1] = 0.0;
	return;
}

float PhaseLeadController_Update(PhaseLeadController *ctr, float input)
{
	//shift samples
	ctr->x[1] = ctr->x[0];
	ctr->y[1] = ctr->y[0];

	ctr->x[0] = input;
	//perform difference eqn
	ctr->y[0] = 4.731729441332686*ctr->x[0] - 4.526505912318582*ctr->x[1] + 0.7947764709858962*ctr->y[1];

	return (ctr->y[0]);
}

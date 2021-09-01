/*
 * control.h
 *
 *  Created on: Jun 11, 2021
 *      Author: adam
 */

#ifndef INC_CONTROL_H_
#define INC_CONTROL_H_

typedef struct
{
	float x_coeff[2];
	float y_coef;
	float x[2];
	float y[2];
}PhaseLeadController;

void PhaseLeadController_Init(PhaseLeadController *ctr);
float PhaseLeadController_Update(PhaseLeadController *controller, float input);

#endif /* INC_CONTROL_H_ */

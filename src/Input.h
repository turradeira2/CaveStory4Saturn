// THIS IS DECOMPILED PROPRIETARY CODE - USE AT YOUR OWN RISK.
//
// The original code belongs to Daisuke "Pixel" Amaya.
//
// Modifications and custom code are under the MIT licence.
// See LICENCE.txt for details.

#pragma once

#include <srl.hpp>

using namespace SRL::Input;
using namespace SRL::Math::Types;


typedef struct _Input
{
	int8_t id;
	Fxp axis_x;
	Fxp axis_y;
	Fxp left_trigger;
	Fxp right_trigger;
} INPUT, *PINPUT;

void InitInput(void);
void ResetInput(void);

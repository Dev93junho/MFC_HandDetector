#include "tiny-dnn-master/tiny_dnn/tiny_dnn.h"
#include "tiny-dnn-master/tiny_dnn/core/framework/tensor.h"
#include "tiny-dnn-master/tiny_dnn/layers/fully_connected_layer.h"
#include "tiny-dnn-master/tiny_dnn/lossfunctions/loss_function.h"

#include <iostream>
#include <vector>
#include "stdafx.h"

using namespace std;

class MLP {
	public:

	string FullyConnected;

	// IMG Data Array distribution

	string InputLayer;

	string HiddenLayers;

	string OutputLayer;

}
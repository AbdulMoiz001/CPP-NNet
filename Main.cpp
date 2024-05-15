#include "DynamicSafeArray.h"
#include "TrainingData.h"
#include "Network.h"
#include "Neuron.h"

using namespace std;

void showArrayVals(string label,array<double> &v)
{
    cout << label << " ";
    for (unsigned i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }

    cout << endl;
}


int main()
{
    TrainingData trainData("trainingData2.txt");

    // e.g., { 3, 2, 1 }
   array<unsigned> topology;
    trainData.getTopology(topology);

    Net myNet(topology);

   array<double> inputVals, targetVals, resultVals;
    int trainingPass = 0;

    while (!trainData.isEof()) {
        ++trainingPass;
        cout << endl << "Pass " << trainingPass;

        // Get new input data and feed it forward:
        if (trainData.getNextInputs(inputVals) != topology[0]) {
            break;
        }
        showArrayVals(": Inputs:", inputVals);
        myNet.feedForward(inputVals);

        // Collect the net's actual output results:
        myNet.getResults(resultVals);
        showArrayVals("Outputs:", resultVals);

        // Train the net what the outputs should have been:
        trainData.getTargetOutputs(targetVals);
        showArrayVals("Targets:", targetVals);
        assert(targetVals.size() == topology.back());

        myNet.backProp(targetVals);

        // Report how well the training is working, average over recent samples:
        cout << "Net recent average error: "
                << myNet.getRecentAverageError() << endl;
    }

    cout << endl << "Done" << endl;
}
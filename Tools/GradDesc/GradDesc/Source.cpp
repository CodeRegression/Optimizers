//--------------------------------------------------
// Startup code module
//
// @author: Wild Boar
//
// @date: 2023-03-31
//--------------------------------------------------

#include "Engine.h"

//--------------------------------------------------
// Execution entry point
//--------------------------------------------------

/**
 * Main Method
 * @param argc The count of the incoming arguments
 * @param argv The number of incoming arguments
 */
int main(int argc, char ** argv) 
{
    auto logger = NVLib::Logger(2);
    logger.StartApplication();

    try
    {
        auto parameters = NVL_App::ArgUtils::Load("GradDesc", argc, argv);
        NVL_App::Engine(&logger, parameters).Run();
    }
    catch (runtime_error exception)
    {
        logger.Log(1, "Error: %s", exception.what());
        exit(EXIT_FAILURE);
    }
    catch (string exception)
    {
        logger.Log(1, "Error: %s", exception.c_str());
        exit(EXIT_FAILURE);
    }

    logger.StopApplication();

    return EXIT_SUCCESS;
}

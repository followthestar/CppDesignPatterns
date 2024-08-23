#include <iostream>
#include <cassert>
#include "DummyDatabase.h"
#include "ConfigurableRecordFinder.h"
#include "PerThreadSingleton.h"
#include "BuildingContext.h"
#include <iostream>

#define TEST

#ifdef TEST
#define TEST_PART(PART1, PART2)
#else
#define PUBLISH
#endif


int main()
{
    std::cout << "Singleton Pattern （单例模式）" << std::endl;

    TEST_PART(RecordFinderTests, DummyTotalPopulationTest)
    {
        DummyDatabase db { };
        ConfigurableRecordFinder rf { db };
        assert(rf.total_population(vector < string > { "alpha", "gamma" }) == 4);
    }

    thread t1([]()
              {
                  cout << "t1: " << PerThreadSingleton::get().id << endl;
              });

    thread t2([]()
              {
                  cout << "t2: " << PerThreadSingleton::get().id << endl;
                  cout << "t2 again: " << PerThreadSingleton::get().id << endl;
              });

    t1.join();
    t2.join();

    auto b = BuildingContext::with_height(3000);
    {
        std::cout << "局部" << std::endl;
        BuildingContext::with_height(3000);
    }
    return 0;
}

#include <iostream>

#include "Benchmark.h"
#include "NumberUtil.h"
#include "RootCalculator.h"
#include "root_table_generator.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    //for (auto n: RootTableGenerator::generateTableUpTo(100)) {
    //    std::cout<<n.first<<" squared is "<<n.second<<"\n";
    //}
    Benchmark benchmark = {};
    Timer* timer = new Timer();
    timer->reset();
    bool benchmarkSuccess=benchmark.runBenchmark(1000);
    double benchmarkDuration=timer->elapsed();
    delete timer;
    if (benchmarkSuccess) {
        std::cout<<benchmark.getAverageTimeOffset()<<"< average time offset "<<std::fixed<< benchmark.getAverageValueOffset()<<" average value offset\n";
    }
    std::cout<<"Benchmark took: "<<benchmarkDuration<<"s \n";
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}
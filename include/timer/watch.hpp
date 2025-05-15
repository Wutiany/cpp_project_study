#ifndef __TIMER_WATCH_HPP__
#define __TIMER_WATCH_HPP__

#include <iostream>
#include <chrono>

using namespace std::chrono;

class TimerBase {
public:
    // 清除计时器
    TimerBase() : start_(system_clock::time_point::min()) {}

    // 清除计时器
    void Clear() 
    {
        start_ = system_clock::time_point::min();
    }

    // 如果计时器正在计时，则返回 true
    bool IsStarted() const 
    {
        return (start_.time_since_epoch() != system_clock::duration(0));
    }

    // 启动计时器
    void Start() 
    {
        start_ = system_clock::now();
    }

    // 得到自计时器开始后的毫秒值
    unsigned long GetMs() 
    {
        if (IsStarted())
        {
            system_clock::duration diff;
            diff = system_clock::now() - start_;
            return (unsigned)(duration_cast<milliseconds>(diff).count());
        }
        return 0;
    }
private:
    system_clock::time_point start_;
};


template <typename T>
class basic_stopwatch : T {
    // typedef typename T BaseTimer;
public:
    // 创建一个秒表类，开始计时一项程序活动
    explicit basic_stopwatch(bool start);
    explicit basic_stopwatch(char const* activity = "Stopwatch", bool start = true);

    basic_stopwatch(std::ostream& log, char const* activity = "StopWatch", bool start = true);

    ~basic_stopwatch();

    // 获取上一次的计时时间
    unsigned LapGet() const;

    // 判断：如果秒表正在运行，则返回true
    bool IsStarted() const;

    // 显示累计时间，一直运行，设置/返回上一次计时时间
    unsigned Show(char const* event = "show");

    // 启动（重启）秒表，设置/返回上次计时时间
    unsigned Start(char const* event_name = "start");

    // 停止正在计时的秒表，设置/返回上次计时时间
    unsigned Stop(char const* event_name = "stop");

private:
    char const* activity_;
    unsigned lap_;          // 上次计时时间
    std::ostream& log_;     // 用于记录事件的流
};
#endif
#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define LOG_INFO(msg) Mylogger::getInstance()->info(msg, __FILE__, __FUNCTION__, __LINE__)
#define LOG_ERROR(msg) Mylogger::getInstance()->error(msg, __FILE__, __FUNCTION__, __LINE__)
#define LOG_WARN(msg) Mylogger::getInstance()->warn(msg, __FILE__, __FUNCTION__, __LINE__)
#define LOG_DEBUG(msg) Mylogger::getInstance()->debug(msg, __FILE__, __FUNCTION__, __LINE__)

class Mylogger
{
public:
    static Mylogger* getInstance(){
        static Mylogger instance;
        return &instance;
    }

    void warn(const char *msg,const char *file,const char *func,int line){
        log("WARN",msg,file,func,line);
    }

    void error(const char*msg,const char *file,const char*func,int line){
        log("ERROR",msg,file,func,line);
    }

    void debug(const char*msg,const char *file,const char *func,int line){
        log("DEBUG",msg,file,func,line);
    }

    void info(const char *msg,const char *file,const char *func,int line){
        log("INFO",msg,file,func,line);
    }

private:
    Mylogger(){
        try{
            log4cpp::PropertyConfigurator::configure("log4cpp.properties"); 
        }catch(log4cpp::ConfigureFailure &f){
            cerr<<"ConfigureFailure Problem:"<<f.what()<<endl;
        }
        _category=&log4cpp::Category::getInstance(std::string("MyCategory"));
    }

    ~Mylogger(){
        log4cpp::Category::shutdown();
    }

    void log(const char *level, const char *msg, const char *file, const char *func, int line) {
      char logMsg[1024];
      snprintf(logMsg,sizeof(logMsg),"[%s:%d-%s] %s",file,line,func,msg);
      if (strcmp(level, "WARN") == 0) {
            _category->warn(logMsg);
        } else if (strcmp(level, "ERROR") == 0) {
            _category->error(logMsg);
        } else if (strcmp(level, "DEBUG") == 0) {
            _category->debug(logMsg);
        } else if (strcmp(level, "INFO") == 0) {
            _category->info(logMsg);
        }
    }
    log4cpp::Category *_category;
};

int main()
{
    printf("hello, world\n");
    // 使用宏定义记录日志，自动获取文件名、函数名及行号
    LOG_INFO("The log is info message");
    LOG_ERROR("The log is error message");
    LOG_WARN("The log is warn message");
    LOG_DEBUG("The log is debug message");
    
    return 0;
}


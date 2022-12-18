#ifndef DELAYED_THREAD_H_
#define DELAYED_THREAD_H_
#include <thread>
#include <future>
class DelayedThread
{
    using promise_t =std::promise<bool>;
    using thread_t = std::thread;
    enum execution_state{
        WAITING,EXECUTING,DISMISSED
    };

    public:
    enum class destruction_action{
        join,detach
    };
    private:
    execution_state m_state=WAITING;
    destruction_action m_on_destruction;
    promise_t m_should_execute;
    thread_t m_thread;

    public:
    DelayedThread(DelayedThread && other) noexcept
    :m_state(std::move(other.m_state)),
    m_on_destruction(std::move(other.m_on_destruction)),
    m_should_execute(std::move(other.m_should_execute)),
    m_thread(std::move(other.m_thread))
    {
        other.m_state = execution_state::DISMISSED;
    };

    template<typename op_t>
    DelayedThread(op_t &&op,destruction_action on_destruction)
    :m_on_destruction(on_destruction),
    m_thread([op=std::forward<op_t>(op),
    should_execute=m_should_execute.get_future()]
    ()mutable{
        if(should_execute.get()){
            op();
        }
    }
    ){};
    ~DelayedThread(){
        if(m_state == WAITING){
            m_should_execute.set_value(false);
        }
        if(m_thread.joinable()){
            switch (m_on_destruction)
            {
            case destruction_action::join:
                m_thread.join();
                break;
            
            case destruction_action::detach:
                m_thread.detach();
                break;
            default:
                break;
            }
        }
    };

    void execute(){
        if(m_state == WAITING){
            m_state = EXECUTING;
            m_should_execute.set_value(true);
        }
    };
};
#endif
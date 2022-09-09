#ifndef FeederNode_hpp
#define FeederNode_hpp

#include <Homie.hpp>
#include "Feeder.hpp"

class FeederNode : public HomieNode {
    public:
        FeederNode(const char* id, const char* name, const char* type);

    protected:
        virtual void setup() override;
        virtual void loop() override;
        virtual void onReadyToOperate() override;
        virtual bool handleInput(const HomieRange& range, const String& property, const String& value);

   private:
        Feeder _feeder;
        bool flagDone;
        bool feederOnHandler(const bool on);
};
#endif //FeederNode_hpp
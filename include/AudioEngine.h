#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H
enum EntityType{BasherAttack, BlasterAttack, BomberAttack, BossAttack, PlayerShipAttack, Damaged, Death  };
class AudioEngine{
    public:
	virtual ~AudioEngine(){}
        virtual void PlaySound(EntityType sound)=0;
        virtual void PlayBackground()=0;
};
#endif

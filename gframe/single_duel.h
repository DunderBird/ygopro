#ifndef SINGLE_DUEL_H
#define SINGLE_DUEL_H

#include "config.h"
#include "network.h"
#include "Replay.h"
#include "../ocgcore/mtrandom.h"

namespace ygo {

class SingleDuel: public DuelMode {
public:
	SingleDuel();
	virtual ~SingleDuel();
	virtual void JoinGame(DuelPlayer* dp, void* pdata, bool is_creater);
	virtual void LeaveGame(DuelPlayer* dp);
	virtual void ToDuelist(DuelPlayer* dp);
	virtual void ToObserver(DuelPlayer* dp);
	virtual void PlayerReady(DuelPlayer* dp, bool ready);
	virtual void PlayerKick(DuelPlayer* dp, unsigned char pos);
	virtual void UpdateDeck(DuelPlayer* dp, void* pdata);
	virtual void StartDuel(DuelPlayer* dp);
	virtual void HandResult(DuelPlayer* dp, unsigned char res);
	virtual void TPResult(DuelPlayer* dp, unsigned char tp);
	virtual void Process();
	virtual int Analyze(char* msgbuffer, unsigned int len);
	virtual void EndDuel();
	
	void WaitforResponse(int playerid);
	void RefreshMzone(int player, int flag = 0x181fff, int use_cache = 1);
	void RefreshSzone(int player, int flag = 0x181fff, int use_cache = 1);
	void RefreshHand(int player, int flag = 0x181fff, int use_cache = 1);
	void RefreshGrave(int player, int flag = 0x181fff, int use_cache = 1);
	void RefreshExtra(int player, int flag = 0x181fff, int use_cache = 1);
	void RefreshSingle(int player, int location, int sequence, int flag = 0x181fff);
	
	static int MessageHandler(long fduel, int type);
	
protected:
	DuelPlayer* players[2];
	bool ready[2];
	Deck pdeck[2];
	unsigned char hand_result[2];
	unsigned char last_response;
	std::set<DuelPlayer*> observers;
	Replay last_replay;
	mtrandom rnd;
};

}

#endif //SINGLE_DUEL_H


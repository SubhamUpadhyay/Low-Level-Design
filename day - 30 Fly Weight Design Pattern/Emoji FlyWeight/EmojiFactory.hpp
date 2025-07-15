#pragma once
#include "Emoji.hpp"
#include <unordered_map>

class EmojiFactory {
private:
    unordered_map<string, Emoji*> emojiPool;

public:
    ~EmojiFactory() {
        for (auto& p : emojiPool) delete p.second;
    }

    Emoji* getEmoji(const string& emojiCode) {
        if (emojiPool.find(emojiCode) == emojiPool.end()) {
            emojiPool[emojiCode] = new Emoji(emojiCode); 
        }
        return emojiPool[emojiCode];
    }
};

#include "EmojiFactory.hpp"

int main() {
    EmojiFactory factory;

    Emoji* smile = factory.getEmoji("SMILE");
    Emoji* heart = factory.getEmoji("HEART");
    Emoji* thumbs = factory.getEmoji("THUMBS");

    smile->render("Alice", "10:00", 100);
    heart->render("Bob", "10:01", 120);
    smile->render("Charlie", "10:02", 140);
    thumbs->render("Alice", "10:03", 160);
    heart->render("Dan", "10:04", 180);

    return 0;
}

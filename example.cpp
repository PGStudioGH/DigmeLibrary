#include <DigmeBox.h>

class Game : public DigmeBox
{
public:
    Game()
    {
        NameApp = "New window";
    };
    ~Game() {};

public:
    bool create() override
    {
        DB_setWindowTitle("Super app!");

        image.loadSprFromImage("test.png");
        DB_initSprGC(&image);

        text.create(13, 1);
        text << "—Ąáâě ®ŕ¤Ą­ !";
        text.update();
        DB_initTextGC(&text);

        return true;
    }
    bool update() override
    {
        DB_fill(C_GREEN);

        DB_drawDecalSprite(8, 8, &image);
        DB_drawDecalText(64, 24, &text);
        
        return true;
    }
private:
    SprGC image;
    TextGC text;
};

DIGMEBOX_MAIN()
{
    Game game;
    game.construct(1024, 512, 256, 128, DB_HARDWARE_ACCELERATED);
    game.start();

    return 0;
}

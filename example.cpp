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
        max_fps = 0;
        DB_setWindowTitle("Super app!");

        image.loadSprFromImage("test.png");
        DB_initSprGC(&image);

        fps.create(13, 1);
        fps << "—Ąáâě ®ŕ¤Ą­ !";
        fps.update();
        DB_initTextGC(&fps);

        return true;
    }
    bool update() override
    {
        DB_fill(C_GREEN);

        DB_drawDecalSprite(8, 8, &image);
        DB_drawDecalText(64, 24, &fps);
        
        return true;
    }
private:
    int max_fps;
    SprGC image;
    TextGC fps;
};

DIGMEBOX_MAIN()
{
    Game game;
    game.construct(1024, 512, 256, 128, DB_HARDWARE_ACCELERATED);
    game.start();

    return 0;
}

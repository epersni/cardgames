add_subdirectory(config)

target_sources(
  graphics
  PRIVATE
    BlackJackView.cpp
    Button.cpp
    Card.cpp
    CenterPiece.cpp
    Hand.cpp
    Node.cpp
    Player.cpp
    TextFactory.cpp
    TextureFactory.cpp
    ViewFactory.cpp
)


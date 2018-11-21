#ifndef INPUT_H
#define INPUT_H
class Input
{
public:
	Input();
	~Input();

	enum Action
	{
		SQUARE, POLY, CIRCLE, CAPSULE, RAY
	};

	void setCurrent(Action);
	Action getCurrent();

private:
	Action m_current;
};
#endif
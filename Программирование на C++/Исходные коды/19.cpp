


class FlyingObject{
	double x,y,z;
	double vx,vy,vz;
	
};

class Dirigible: FlyingObject{
	double BurnerPower;
	
};

struct Aeroplane: FlyingObject{
	double EnginePower;
	
};

int main()
{
	
	Aeroplane airoplane;
	Dirigible dirigible;
	FlyingObject *fpo[2];
	fpo[0] = &airoplane;
	fpo[1] = &dirigible;
	
}
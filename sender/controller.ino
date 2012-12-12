
int deadCenter = RIGHTHATDEADCENTER;

#define ANALOGMAX 32767
#define ANALOGMIN -32768

int getRightHatY(int outMin, int outMax) {
  return getRightHat(RightHatY,outMin,outMax);
}

int getRightHatX(int outMin, int outMax) {
  return getRightHat(RightHatX,outMin,outMax);
}

int getRightHat(AnalogHat axis, int outMin, int outMax) {
    int yValue = Xbox.getAnalogHat(axis);
    if (yValue >= deadCenter) {
      yValue = yValue - deadCenter;
    } else if(yValue <= (deadCenter*-1)) {
      yValue = yValue+deadCenter;
    } else {
      yValue = 0;
    }
    int yMap = map (yValue, (ANALOGMIN+deadCenter),(ANALOGMAX-deadCenter), outMin, outMax);
    return yMap;

}

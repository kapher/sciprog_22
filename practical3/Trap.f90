program Trap
  implicit none
  integer (kind=4) :: N=12, i
  real (kind=4) :: a =0.0, b_deg =60.0
  real (kind=4) :: pi, b_rad, area, mult_rad


  !Convert b=pi/3 to radians
  pi=atan(1.0)*4.0
  b_rad=(pi*b_deg)/180.0

  ! Sum tan(a) and tan(b) a=x0, b=xN
  area= tan(a)+tan(b_rad)
  ! Calculate 2*f(x1), 2*f(x2), .., 2*f(x11)
  do i=5, 55, 5
    area=area+2*tan((pi*i)/180.0)
  end do

  !Multiply by (pi/3)/(2*12)
  !Convert to radians first
  mult_rad=(pi*(b_deg/(2*N)))/180.0
  area= mult_rad*area
  !print the approximated area and actual value
  write(6, *) 'Approximation ', area
  write(6, *) 'Real result', log(2.0)

  stop
end program Trap

reset

#f(x) = (x>=-0.263 && x<=-0.23) ? b*exp(c*x) : 1/0
#pi = 3.1415926536
#a = -2
#b = -1.5
#f = 1000
#a = -2.08668
#b = -1.67946
#f = 1000
#fase = 3.18712
#f(x)= a+b*sin(2*pi*f*x/1000+fase)
#fit [0.320:0.37] f(x) '../aaaa_output.txt' u ($1*1000):2:3 via a, b
#f(x) = (x>=0.320 && x<=0.37) ? a+b*x : 1/0
#fit f(x) '../dati/1.txt' u ($1*1000):2:3 via fase
#fit f(x) '../dati/1.txt' u ($1*1000):2:3 via a, b, f, fase

set samples 10000
#set format x "%.2f"
#set logscale y
set format y "%.1f"
set xlabel "T"
set ylabel "B(T)"
#set y2label "V_2 [V]"
#set y2tics
set mxtics 5
set mytics 5
set key bottom right
set grid
set bars small
#set terminal jpeg enhanced font "arial" 19 size 1280,720 #1152, 648 #1280,720 #1920,1080
#set output "grafico_1.jpeg"
set terminal svg enhanced font "arial,20" size 800, 600 dashed# 1280,720 dashed 1280, 960
#set terminal svg enhanced font "arial,32" size 1280, 960 dashed# 1280,720 dashed 1280, 960
set output "grafico_1.svg"
#set terminal pngcairo enhanced font "arial,19" size 1280,720 dashed
#set output "grafico_1.png"

set xrange [0.1:10]

#k_b = 1.381*10**(-23)
#epsilon = 
k_b_epsilon_He=10.22
sigma = 2.556*10**(-10)
N_a=6.022*10**(23)

plot './file.dat' u ($1):($2) w l lt 1 lw 1 lc rgb 'red' ti 'B(T)' axes x1y1, './He.txt' u (($1+273.15)/k_b_epsilon_He):($2*10**(-6)/((sigma**3)*N_a)) lt 1 lc rgb 'blue' ti 'He' axes x1y1



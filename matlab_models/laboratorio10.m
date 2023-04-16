% Laboratorio N° 10
% variante 2 
% Enunciado:
% Trazar un gráfico de superficie para un numero dado de 
% puntos lo largo de cada eje y un esquema de color dado
% elipsoide para 1000 puntos con paso de 0.6. color cube

% formula de elipsoide:
% (x - xo)^2/a^2 + (y - y0)^2/b^2 + (z - z0)^2/c^2 = 1

% definiendo los parametros para el elipsoide
a = 3.0;    b = 4.0;    c = 5.0;
x0 = 0;     y0 = 0;     z0 = 0;

% definiendo las variables x, y
x = -6:0.6:6;
y = -8:0.6:8;

% creando la malla para los ejes X, Y
[X, Y] = meshgrid(x, y);

% formula del elipsoide
zc1 = z0 + sqrt( 1 - (X - x0).^2/a^2 - (Y - y0).^2/b^2 ) * c;
zc2 = z0 - sqrt( 1 - (X - x0).^2/a^2 - (Y - y0).^2/b^2 ) * c;

% eliminar posibles valores de zc1 que pert. a los complejos
ind1 = abs(imag(zc1)) > 0;
zc1(ind1)= NaN;

% eliminar posibles valores de zc2 que pert. a los complejos
ind2 = abs(imag(zc2)) > 0;
zc2(ind2) = NaN;

% construir grafica
figure
surf(X, Y, zc1);
hold on
surf(X, Y, zc2);
colormap(colorcube);

% especificaciones de la grafica
title("Grafica de la funcion z(x, y)");
xlabel("x");
ylabel("y");
zlabel("z");


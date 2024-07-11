import sympy as sp
import matplotlib.pyplot as plt

# Define the coordinates of the triangle vertices
A = sp.Point(1, 5)
B = sp.Point(0, 0)
C = sp.Point(6, 0)

# Function to find the orthocenter of a triangle using SymPy
def orthocenter(A, B, C):
    alt1 = sp.Line(A, B).perpendicular_line(C)
    alt2 = sp.Line(B, C).perpendicular_line(A)
    H = alt1.intersection(alt2)[0]
    return H

# Calculate orthocenter H
H = orthocenter(A, B, C)

# Midpoint I of AH
I = A.midpoint(H)

# Function to find the foot of the perpendicular from a point to a line using SymPy
def foot_of_perpendicular(P, A, B):
    line = sp.Line(A, B)
    perp = line.perpendicular_line(P)
    foot = line.intersection(perp)[0]
    return foot

# Altitude BE from B perpendicular to AC
E = foot_of_perpendicular(B, A, C)

# Altitude CF from C perpendicular to AB
F = foot_of_perpendicular(C, A, B)

# Intersection J of EF and AH
line_EF = sp.Line(E, F)
line_AH = sp.Line(A, H)
J = line_EF.intersection(line_AH)[0]

# Extract coordinates for plotting
A_coords = (float(A.x), float(A.y))
B_coords = (float(B.x), float(B.y))
C_coords = (float(C.x), float(C.y))
H_coords = (float(H.x), float(H.y))
I_coords = (float(I.x), float(I.y))
E_coords = (float(E.x), float(E.y))
F_coords = (float(F.x), float(F.y))
J_coords = (float(J.x), float(J.y))

# Plotting the figure
fig, ax = plt.subplots()
ax.plot([A_coords[0], B_coords[0]], [A_coords[1], B_coords[1]], 'k-')
ax.plot([B_coords[0], C_coords[0]], [B_coords[1], C_coords[1]], 'k-')
ax.plot([C_coords[0], A_coords[0]], [C_coords[1], A_coords[1]], 'k-')

ax.plot([B_coords[0], E_coords[0]], [B_coords[1], E_coords[1]], 'b--')
ax.plot([C_coords[0], F_coords[0]], [C_coords[1], F_coords[1]], 'b--')
ax.plot([A_coords[0], H_coords[0]], [A_coords[1], H_coords[1]], 'b--')

ax.plot([E_coords[0], F_coords[0]], [E_coords[1], F_coords[1]], 'g--')
ax.plot([A_coords[0], H_coords[0]], [A_coords[1], H_coords[1]], 'r--')

ax.scatter(*A_coords, color='red')
ax.scatter(*B_coords, color='red')
ax.scatter(*C_coords, color='red')
ax.scatter(*H_coords, color='blue')
ax.scatter(*I_coords, color='purple')
ax.scatter(*E_coords, color='orange')
ax.scatter(*F_coords, color='orange')
ax.scatter(*J_coords, color='green')

ax.text(A_coords[0], A_coords[1], 'A', fontsize=12, ha='right')
ax.text(B_coords[0], B_coords[1], 'B', fontsize=12, ha='right')
ax.text(C_coords[0], C_coords[1], 'C', fontsize=12, ha='right')
ax.text(H_coords[0], H_coords[1], 'H', fontsize=12, ha='left')
ax.text(I_coords[0], I_coords[1], 'I', fontsize=12, ha='right')
ax.text(E_coords[0], E_coords[1], 'E', fontsize=12, ha='left')
ax.text(F_coords[0], F_coords[1], 'F', fontsize=12, ha='right')
ax.text(J_coords[0], J_coords[1], 'J', fontsize=12, ha='left')

ax.set_aspect('equal', adjustable='box')
plt.grid(True)
plt.show()

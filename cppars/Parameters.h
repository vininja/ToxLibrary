#pragma once

class OP_Inputs;
class OP_ParameterManager;

#pragma region ParNames and ParLabels

// Names of the parameters

constexpr static char ResetName[] = "Reset";
constexpr static char ResetLabel[] = "Reset";

constexpr static char SimulateName[] = "Simulate";
constexpr static char SimulateLabel[] = "Simulate";

constexpr static char RadiusName[] = "Radius";
constexpr static char RadiusLabel[] = "Radius";

constexpr static char MaxspeedName[] = "Maxspeed";
constexpr static char MaxspeedLabel[] = "Max Speed";

constexpr static char GravityName[] = "Gravity";
constexpr static char GravityLabel[] = "Gravity";

constexpr static char FpsName[] = "Fps";
constexpr static char FpsLabel[] = "FPS";

constexpr static char NumsubstepsName[] = "Numsubsteps";
constexpr static char NumsubstepsLabel[] = "Num Substeps";

constexpr static char NumiterationsName[] = "Numiterations";
constexpr static char NumiterationsLabel[] = "Num Iterations";

constexpr static char MaxparticlesName[] = "Maxparticles";
constexpr static char MaxparticlesLabel[] = "Max Number of Particles";

constexpr static char MaxdiffuseparticlesName[] = "Maxdiffuseparticles";
constexpr static char MaxdiffuseparticlesLabel[] = "Max Number of Diffuse Particles";

constexpr static char ForceschopName[] = "Forceschop";
constexpr static char ForceschopLabel[] = "Forcefields CHOP";

constexpr static char DampingName[] = "Damping";
constexpr static char DampingLabel[] = "Damping";

constexpr static char DynamicfrictionName[] = "Dynamicfriction";
constexpr static char DynamicfrictionLabel[] = "Dynamic Friction";

constexpr static char RestitutionName[] = "Restitution";
constexpr static char RestitutionLabel[] = "Restitution";

constexpr static char AdhesionName[] = "Adhesion";
constexpr static char AdhesionLabel[] = "Adhesion";

constexpr static char DissipationName[] = "Dissipation";
constexpr static char DissipationLabel[] = "Dissipation";

constexpr static char CohesionName[] = "Cohesion";
constexpr static char CohesionLabel[] = "Cohesion";

constexpr static char SurfacetensionName[] = "Surfacetension";
constexpr static char SurfacetensionLabel[] = "Surface Tension";

constexpr static char ViscosityName[] = "Viscosity";
constexpr static char ViscosityLabel[] = "Viscosity";

constexpr static char VorticityconfinementName[] = "Vorticityconfinement";
constexpr static char VorticityconfinementLabel[] = "Vorticity Confinement";

constexpr static char SmoothingstrengthName[] = "Smoothingstrength";
constexpr static char SmoothingstrengthLabel[] = "Smoothing Strength";

constexpr static char AnisotropyscaleName[] = "Anisotropyscale";
constexpr static char AnisotropyscaleLabel[] = "Anisotropy Scale";

constexpr static char ColplaneschopName[] = "Colplaneschop";
constexpr static char ColplaneschopLabel[] = "Collision Planes CHOP";

constexpr static char CollisionsphereschopName[] = "Collisionsphereschop";
constexpr static char CollisionsphereschopLabel[] = "Collision Spheres CHOP";

constexpr static char ColboxeschopName[] = "Colboxeschop";
constexpr static char ColboxeschopLabel[] = "Collision Boxes CHOP";

constexpr static char TrianglespolysopName[] = "Trianglespolysop";
constexpr static char TrianglespolysopLabel[] = "Triangles Polygons SOP";

constexpr static char DeformingmeshName[] = "Deformingmesh";
constexpr static char DeformingmeshLabel[] = "Deforming Mesh";

constexpr static char MeshtranslationName[] = "Meshtranslation";
constexpr static char MeshtranslationLabel[] = "Mesh Translation";

constexpr static char MeshrotationName[] = "Meshrotation";
constexpr static char MeshrotationLabel[] = "Mesh Rotation";

constexpr static char CollisiondistanceName[] = "Collisiondistance";
constexpr static char CollisiondistanceLabel[] = "Collision Distance";

constexpr static char ShapecollisionmarginName[] = "Shapecollisionmargin";
constexpr static char ShapecollisionmarginLabel[] = "Shape Collision Margin";

constexpr static char Flexcloth0Name[] = "Flexcloth0";
constexpr static char Flexcloth0Label[] = "Mesh 0";

constexpr static char Anchorscloth0Name[] = "Anchorscloth0";
constexpr static char Anchorscloth0Label[] = "Anchors 0";

constexpr static char Flexcloth1Name[] = "Flexcloth1";
constexpr static char Flexcloth1Label[] = "Mesh 1";

constexpr static char Anchorscloth1Name[] = "Anchorscloth1";
constexpr static char Anchorscloth1Label[] = "Anchors 1";

constexpr static char GiveName[] = "Give";
constexpr static char GiveLabel[] = "Give";

constexpr static char StrechclothName[] = "Strechcloth";
constexpr static char StrechclothLabel[] = "Stretch Stiffness";

constexpr static char BendclothName[] = "Bendcloth";
constexpr static char BendclothLabel[] = "Bend Stiffness";

constexpr static char PressureName[] = "Pressure";
constexpr static char PressureLabel[] = "Pressure";

constexpr static char DragName[] = "Drag";
constexpr static char DragLabel[] = "Drag";

constexpr static char LiftName[] = "Lift";
constexpr static char LiftLabel[] = "Lift";

constexpr static char WindName[] = "Wind";
constexpr static char WindLabel[] = "Wind";


#pragma endregion

#pragma region Menus
#pragma endregion


#pragma region Parameters
class Parameters
{
public:
	static void		setup(OP_ParameterManager*);

	// Reset
	static bool		evalReset(const OP_Inputs* input);

	// Simulate
	static bool		evalSimulate(const OP_Inputs* input);

	// Radius
	static double		evalRadius(const OP_Inputs* input);

	// Max Speed
	static double		evalMaxspeed(const OP_Inputs* input);

	// Gravity
	static std::array<double, 3>		evalGravity(const OP_Inputs* input);

	// FPS
	static int		evalFps(const OP_Inputs* input);

	// Num Substeps
	static int		evalNumsubsteps(const OP_Inputs* input);

	// Num Iterations
	static int		evalNumiterations(const OP_Inputs* input);

	// Max Number of Particles
	static int		evalMaxparticles(const OP_Inputs* input);

	// Max Number of Diffuse Particles
	static int		evalMaxdiffuseparticles(const OP_Inputs* input);

	// Forcefields CHOP
	static const OP_CHOPInput*		evalForceschop(const OP_Inputs* input);

	// Damping
	static double		evalDamping(const OP_Inputs* input);

	// Dynamic Friction
	static double		evalDynamicfriction(const OP_Inputs* input);

	// Restitution
	static double		evalRestitution(const OP_Inputs* input);

	// Adhesion
	static double		evalAdhesion(const OP_Inputs* input);

	// Dissipation
	static double		evalDissipation(const OP_Inputs* input);

	// Cohesion
	static double		evalCohesion(const OP_Inputs* input);

	// Surface Tension
	static double		evalSurfacetension(const OP_Inputs* input);

	// Viscosity
	static double		evalViscosity(const OP_Inputs* input);

	// Vorticity Confinement
	static double		evalVorticityconfinement(const OP_Inputs* input);

	// Smoothing Strength
	static double		evalSmoothingstrength(const OP_Inputs* input);

	// Anisotropy Scale
	static double		evalAnisotropyscale(const OP_Inputs* input);

	// Collision Planes CHOP
	static const OP_CHOPInput*		evalColplaneschop(const OP_Inputs* input);

	// Collision Spheres CHOP
	static const OP_CHOPInput*		evalCollisionsphereschop(const OP_Inputs* input);

	// Collision Boxes CHOP
	static const OP_CHOPInput*		evalColboxeschop(const OP_Inputs* input);

	// Triangles Polygons SOP
	static const OP_SOPInput*		evalTrianglespolysop(const OP_Inputs* input);

	// Deforming Mesh
	static bool		evalDeformingmesh(const OP_Inputs* input);

	// Mesh Translation
	static std::array<double, 3>		evalMeshtranslation(const OP_Inputs* input);

	// Mesh Rotation
	static std::array<double, 3>		evalMeshrotation(const OP_Inputs* input);

	// Collision Distance
	static double		evalCollisiondistance(const OP_Inputs* input);

	// Shape Collision Margin
	static double		evalShapecollisionmargin(const OP_Inputs* input);

	// Mesh 0
	static const OP_SOPInput*		evalFlexcloth0(const OP_Inputs* input);

	// Anchors 0
	static const OP_SOPInput*		evalAnchorscloth0(const OP_Inputs* input);

	// Mesh 1
	static const OP_SOPInput*		evalFlexcloth1(const OP_Inputs* input);

	// Anchors 1
	static const OP_SOPInput*		evalAnchorscloth1(const OP_Inputs* input);

	// Give
	static double		evalGive(const OP_Inputs* input);

	// Stretch Stiffness
	static double		evalStrechcloth(const OP_Inputs* input);

	// Bend Stiffness
	static double		evalBendcloth(const OP_Inputs* input);

	// Pressure
	static double		evalPressure(const OP_Inputs* input);

	// Drag
	static double		evalDrag(const OP_Inputs* input);

	// Lift
	static double		evalLift(const OP_Inputs* input);

	// Wind
	static std::array<double, 3>		evalWind(const OP_Inputs* input);


};
#pragma endregion
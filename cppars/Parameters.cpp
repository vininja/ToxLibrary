#include <string>
#include <array>
#include "CPlusPlus_Common.h"
#include "Parameters.h"

#pragma region Evals

bool
Parameters::evalReset(const OP_Inputs* input)
{
	return input->getParInt(ResetName) ? true : false;
}

bool
Parameters::evalSimulate(const OP_Inputs* input)
{
	return input->getParInt(SimulateName) ? true : false;
}

double
Parameters::evalRadius(const OP_Inputs* input)
{
	return input->getParDouble(RadiusName);
}

double
Parameters::evalMaxspeed(const OP_Inputs* input)
{
	return input->getParDouble(MaxspeedName);
}

std::array<double, 3>
Parameters::evalGravity(const OP_Inputs* input)
{
	std::array<double, 3> vals;
	input->getParDouble3(GravityName, vals[0], vals[1], vals[2]);
	return vals;
}

int
Parameters::evalFps(const OP_Inputs* input)
{
	return input->getParInt(FpsName);
}

int
Parameters::evalNumsubsteps(const OP_Inputs* input)
{
	return input->getParInt(NumsubstepsName);
}

int
Parameters::evalNumiterations(const OP_Inputs* input)
{
	return input->getParInt(NumiterationsName);
}

int
Parameters::evalMaxparticles(const OP_Inputs* input)
{
	return input->getParInt(MaxparticlesName);
}

int
Parameters::evalMaxdiffuseparticles(const OP_Inputs* input)
{
	return input->getParInt(MaxdiffuseparticlesName);
}

const OP_CHOPInput*
Parameters::evalForceschop(const OP_Inputs* input)
{
	return input->getParCHOP(ForceschopName);
}

double
Parameters::evalDamping(const OP_Inputs* input)
{
	return input->getParDouble(DampingName);
}

double
Parameters::evalDynamicfriction(const OP_Inputs* input)
{
	return input->getParDouble(DynamicfrictionName);
}

double
Parameters::evalRestitution(const OP_Inputs* input)
{
	return input->getParDouble(RestitutionName);
}

double
Parameters::evalAdhesion(const OP_Inputs* input)
{
	return input->getParDouble(AdhesionName);
}

double
Parameters::evalDissipation(const OP_Inputs* input)
{
	return input->getParDouble(DissipationName);
}

double
Parameters::evalCohesion(const OP_Inputs* input)
{
	return input->getParDouble(CohesionName);
}

double
Parameters::evalSurfacetension(const OP_Inputs* input)
{
	return input->getParDouble(SurfacetensionName);
}

double
Parameters::evalViscosity(const OP_Inputs* input)
{
	return input->getParDouble(ViscosityName);
}

double
Parameters::evalVorticityconfinement(const OP_Inputs* input)
{
	return input->getParDouble(VorticityconfinementName);
}

double
Parameters::evalSmoothingstrength(const OP_Inputs* input)
{
	return input->getParDouble(SmoothingstrengthName);
}

double
Parameters::evalAnisotropyscale(const OP_Inputs* input)
{
	return input->getParDouble(AnisotropyscaleName);
}

const OP_CHOPInput*
Parameters::evalColplaneschop(const OP_Inputs* input)
{
	return input->getParCHOP(ColplaneschopName);
}

const OP_CHOPInput*
Parameters::evalCollisionsphereschop(const OP_Inputs* input)
{
	return input->getParCHOP(CollisionsphereschopName);
}

const OP_CHOPInput*
Parameters::evalColboxeschop(const OP_Inputs* input)
{
	return input->getParCHOP(ColboxeschopName);
}

const OP_SOPInput*
Parameters::evalTrianglespolysop(const OP_Inputs* input)
{
	return input->getParSOP(TrianglespolysopName);
}

bool
Parameters::evalDeformingmesh(const OP_Inputs* input)
{
	return input->getParInt(DeformingmeshName) ? true : false;
}

std::array<double, 3>
Parameters::evalMeshtranslation(const OP_Inputs* input)
{
	std::array<double, 3> vals;
	input->getParDouble3(MeshtranslationName, vals[0], vals[1], vals[2]);
	return vals;
}

std::array<double, 3>
Parameters::evalMeshrotation(const OP_Inputs* input)
{
	std::array<double, 3> vals;
	input->getParDouble3(MeshrotationName, vals[0], vals[1], vals[2]);
	return vals;
}

double
Parameters::evalCollisiondistance(const OP_Inputs* input)
{
	return input->getParDouble(CollisiondistanceName);
}

double
Parameters::evalShapecollisionmargin(const OP_Inputs* input)
{
	return input->getParDouble(ShapecollisionmarginName);
}

const OP_SOPInput*
Parameters::evalFlexcloth0(const OP_Inputs* input)
{
	return input->getParSOP(Flexcloth0Name);
}

const OP_SOPInput*
Parameters::evalAnchorscloth0(const OP_Inputs* input)
{
	return input->getParSOP(Anchorscloth0Name);
}

const OP_SOPInput*
Parameters::evalFlexcloth1(const OP_Inputs* input)
{
	return input->getParSOP(Flexcloth1Name);
}

const OP_SOPInput*
Parameters::evalAnchorscloth1(const OP_Inputs* input)
{
	return input->getParSOP(Anchorscloth1Name);
}

double
Parameters::evalGive(const OP_Inputs* input)
{
	return input->getParDouble(GiveName);
}

double
Parameters::evalStrechcloth(const OP_Inputs* input)
{
	return input->getParDouble(StrechclothName);
}

double
Parameters::evalBendcloth(const OP_Inputs* input)
{
	return input->getParDouble(BendclothName);
}

double
Parameters::evalPressure(const OP_Inputs* input)
{
	return input->getParDouble(PressureName);
}

double
Parameters::evalDrag(const OP_Inputs* input)
{
	return input->getParDouble(DragName);
}

double
Parameters::evalLift(const OP_Inputs* input)
{
	return input->getParDouble(LiftName);
}

std::array<double, 3>
Parameters::evalWind(const OP_Inputs* input)
{
	std::array<double, 3> vals;
	input->getParDouble3(WindName, vals[0], vals[1], vals[2]);
	return vals;
}


#pragma endregion

#pragma region Setup

void
Parameters::setup(OP_ParameterManager* manager)
{
	{
		OP_NumericParameter p;
		p.name = ResetName;
		p.label = ResetLabel;
		p.page = "Custom";
		p.defaultValues[0] = false;

		OP_ParAppendResult res = manager->appendToggle(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = SimulateName;
		p.label = SimulateLabel;
		p.page = "Custom";
		p.defaultValues[0] = false;

		OP_ParAppendResult res = manager->appendToggle(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = RadiusName;
		p.label = RadiusLabel;
		p.page = "Custom";
		p.defaultValues[0] = 0.0;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 1.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendFloat(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = MaxspeedName;
		p.label = MaxspeedLabel;
		p.page = "Custom";
		p.defaultValues[0] = 0.0;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 20.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendFloat(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = GravityName;
		p.label = GravityLabel;
		p.page = "Custom";
		
		const int ArraySize = 3;

		const std::array<double, ArraySize>  DefaultValues = { 0.0, 0.0, 0.0 };
		const std::array<double, ArraySize>  MinSliders = { 0.0, 0.0, 0.0 };
		const std::array<double, ArraySize>  MaxSliders = { 1.0, 1.0, 1.0 };
		const std::array<double, ArraySize>  MinValues = { 0.0, 0.0, 0.0 };
		const std::array<double, ArraySize>  MaxValues = { 1.0, 1.0, 1.0 };
		const std::array<bool, ArraySize>  ClampMins = { false, false, false };
		const std::array<bool, ArraySize>  ClampMaxes = { false, false, false };
		for (int i = 0; i < DefaultValues.size(); ++i)
		{
			p.defaultValues[i] = DefaultValues[i];
			p.minSliders[i] = MinSliders[i];
			p.maxSliders[i] = MaxSliders[i];
			p.minValues[i] = MinValues[i];
			p.maxValues[i] = MaxValues[i];
			p.clampMins[i] = ClampMins[i];
			p.clampMaxes[i] = ClampMaxes[i];
		}
		OP_ParAppendResult res = manager->appendFloat(p, DefaultValues.size());

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = FpsName;
		p.label = FpsLabel;
		p.page = "Solver";
		p.defaultValues[0] = 60;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 100.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendInt(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = NumsubstepsName;
		p.label = NumsubstepsLabel;
		p.page = "Solver";
		p.defaultValues[0] = 3;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 3.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendInt(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = NumiterationsName;
		p.label = NumiterationsLabel;
		p.page = "Solver";
		p.defaultValues[0] = 3;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 3.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendInt(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = MaxparticlesName;
		p.label = MaxparticlesLabel;
		p.page = "Solver";
		p.defaultValues[0] = 160000;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 1.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendInt(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = MaxdiffuseparticlesName;
		p.label = MaxdiffuseparticlesLabel;
		p.page = "Solver";
		p.defaultValues[0] = 0;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 1.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendInt(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_StringParameter p;
		p.name = ForceschopName;
		p.label = ForceschopLabel;
		p.page = "Solver";
		p.defaultValue = "";
		OP_ParAppendResult res = manager->appendCHOP(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = DampingName;
		p.label = DampingLabel;
		p.page = "PartsParams";
		p.defaultValues[0] = 0.0;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 1.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendFloat(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = DynamicfrictionName;
		p.label = DynamicfrictionLabel;
		p.page = "PartsParams";
		p.defaultValues[0] = 0.0;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 1.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendFloat(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = RestitutionName;
		p.label = RestitutionLabel;
		p.page = "PartsParams";
		p.defaultValues[0] = 0.0;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 1.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendFloat(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = AdhesionName;
		p.label = AdhesionLabel;
		p.page = "PartsParams";
		p.defaultValues[0] = 0.0;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 1.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendFloat(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = DissipationName;
		p.label = DissipationLabel;
		p.page = "PartsParams";
		p.defaultValues[0] = 0.0;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 1.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendFloat(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = CohesionName;
		p.label = CohesionLabel;
		p.page = "PartsParams";
		p.defaultValues[0] = 0.0;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 1.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendFloat(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = SurfacetensionName;
		p.label = SurfacetensionLabel;
		p.page = "PartsParams";
		p.defaultValues[0] = 0.0;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 1.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendFloat(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = ViscosityName;
		p.label = ViscosityLabel;
		p.page = "PartsParams";
		p.defaultValues[0] = 0.0;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 1.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendFloat(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = VorticityconfinementName;
		p.label = VorticityconfinementLabel;
		p.page = "PartsParams";
		p.defaultValues[0] = 0.0;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 1.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendFloat(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = SmoothingstrengthName;
		p.label = SmoothingstrengthLabel;
		p.page = "PartsParams";
		p.defaultValues[0] = 1.0;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 1.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendFloat(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = AnisotropyscaleName;
		p.label = AnisotropyscaleLabel;
		p.page = "PartsParams";
		p.defaultValues[0] = 1.0;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 1.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendFloat(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_StringParameter p;
		p.name = ColplaneschopName;
		p.label = ColplaneschopLabel;
		p.page = "Collisions";
		p.defaultValue = "";
		OP_ParAppendResult res = manager->appendCHOP(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_StringParameter p;
		p.name = CollisionsphereschopName;
		p.label = CollisionsphereschopLabel;
		p.page = "Collisions";
		p.defaultValue = "";
		OP_ParAppendResult res = manager->appendCHOP(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_StringParameter p;
		p.name = ColboxeschopName;
		p.label = ColboxeschopLabel;
		p.page = "Collisions";
		p.defaultValue = "";
		OP_ParAppendResult res = manager->appendCHOP(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_StringParameter p;
		p.name = TrianglespolysopName;
		p.label = TrianglespolysopLabel;
		p.page = "Collisions";
		p.defaultValue = "";
		OP_ParAppendResult res = manager->appendSOP(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = DeformingmeshName;
		p.label = DeformingmeshLabel;
		p.page = "Collisions";
		p.defaultValues[0] = false;

		OP_ParAppendResult res = manager->appendToggle(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = MeshtranslationName;
		p.label = MeshtranslationLabel;
		p.page = "Collisions";
		
		const int ArraySize = 3;

		const std::array<double, ArraySize>  DefaultValues = { 0.0, 0.0, 0.0 };
		const std::array<double, ArraySize>  MinSliders = { 0.0, 0.0, 0.0 };
		const std::array<double, ArraySize>  MaxSliders = { 1.0, 1.0, 1.0 };
		const std::array<double, ArraySize>  MinValues = { 0.0, 0.0, 0.0 };
		const std::array<double, ArraySize>  MaxValues = { 1.0, 1.0, 1.0 };
		const std::array<bool, ArraySize>  ClampMins = { false, false, false };
		const std::array<bool, ArraySize>  ClampMaxes = { false, false, false };
		for (int i = 0; i < DefaultValues.size(); ++i)
		{
			p.defaultValues[i] = DefaultValues[i];
			p.minSliders[i] = MinSliders[i];
			p.maxSliders[i] = MaxSliders[i];
			p.minValues[i] = MinValues[i];
			p.maxValues[i] = MaxValues[i];
			p.clampMins[i] = ClampMins[i];
			p.clampMaxes[i] = ClampMaxes[i];
		}
		OP_ParAppendResult res = manager->appendFloat(p, DefaultValues.size());

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = MeshrotationName;
		p.label = MeshrotationLabel;
		p.page = "Collisions";
		
		const int ArraySize = 3;

		const std::array<double, ArraySize>  DefaultValues = { 0.0, 0.0, 0.0 };
		const std::array<double, ArraySize>  MinSliders = { 0.0, 0.0, 0.0 };
		const std::array<double, ArraySize>  MaxSliders = { 1.0, 1.0, 1.0 };
		const std::array<double, ArraySize>  MinValues = { 0.0, 0.0, 0.0 };
		const std::array<double, ArraySize>  MaxValues = { 1.0, 1.0, 1.0 };
		const std::array<bool, ArraySize>  ClampMins = { false, false, false };
		const std::array<bool, ArraySize>  ClampMaxes = { false, false, false };
		for (int i = 0; i < DefaultValues.size(); ++i)
		{
			p.defaultValues[i] = DefaultValues[i];
			p.minSliders[i] = MinSliders[i];
			p.maxSliders[i] = MaxSliders[i];
			p.minValues[i] = MinValues[i];
			p.maxValues[i] = MaxValues[i];
			p.clampMins[i] = ClampMins[i];
			p.clampMaxes[i] = ClampMaxes[i];
		}
		OP_ParAppendResult res = manager->appendFloat(p, DefaultValues.size());

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = CollisiondistanceName;
		p.label = CollisiondistanceLabel;
		p.page = "Collisions";
		p.defaultValues[0] = 0.0;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 1.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendFloat(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = ShapecollisionmarginName;
		p.label = ShapecollisionmarginLabel;
		p.page = "Collisions";
		p.defaultValues[0] = 0.0;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 1.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendFloat(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_StringParameter p;
		p.name = Flexcloth0Name;
		p.label = Flexcloth0Label;
		p.page = "Cloths";
		p.defaultValue = "";
		OP_ParAppendResult res = manager->appendSOP(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_StringParameter p;
		p.name = Anchorscloth0Name;
		p.label = Anchorscloth0Label;
		p.page = "Cloths";
		p.defaultValue = "";
		OP_ParAppendResult res = manager->appendSOP(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_StringParameter p;
		p.name = Flexcloth1Name;
		p.label = Flexcloth1Label;
		p.page = "Cloths";
		p.defaultValue = "";
		OP_ParAppendResult res = manager->appendSOP(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_StringParameter p;
		p.name = Anchorscloth1Name;
		p.label = Anchorscloth1Label;
		p.page = "Cloths";
		p.defaultValue = "";
		OP_ParAppendResult res = manager->appendSOP(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = GiveName;
		p.label = GiveLabel;
		p.page = "Cloths";
		p.defaultValues[0] = 0.0;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 1.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendFloat(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = StrechclothName;
		p.label = StrechclothLabel;
		p.page = "Cloths";
		p.defaultValues[0] = 0.0;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 1.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendFloat(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = BendclothName;
		p.label = BendclothLabel;
		p.page = "Cloths";
		p.defaultValues[0] = 0.0;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 1.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendFloat(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = PressureName;
		p.label = PressureLabel;
		p.page = "Cloths";
		p.defaultValues[0] = 0.0;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 1.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendFloat(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = DragName;
		p.label = DragLabel;
		p.page = "Cloths";
		p.defaultValues[0] = 0.0;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 1.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendFloat(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = LiftName;
		p.label = LiftLabel;
		p.page = "Cloths";
		p.defaultValues[0] = 0.0;
		p.minSliders[0] = 0.0;
		p.maxSliders[0] = 1.0;
		p.minValues[0] = 0.0;
		p.maxValues[0] = 1.0;
		p.clampMins[0] = false;
		p.clampMaxes[0] = false;
		OP_ParAppendResult res = manager->appendFloat(p);

		assert(res == OP_ParAppendResult::Success);
	}

	{
		OP_NumericParameter p;
		p.name = WindName;
		p.label = WindLabel;
		p.page = "Cloths";
		
		const int ArraySize = 3;

		const std::array<double, ArraySize>  DefaultValues = { 0.0, 0.0, 0.0 };
		const std::array<double, ArraySize>  MinSliders = { 0.0, 0.0, 0.0 };
		const std::array<double, ArraySize>  MaxSliders = { 1.0, 1.0, 1.0 };
		const std::array<double, ArraySize>  MinValues = { 0.0, 0.0, 0.0 };
		const std::array<double, ArraySize>  MaxValues = { 1.0, 1.0, 1.0 };
		const std::array<bool, ArraySize>  ClampMins = { false, false, false };
		const std::array<bool, ArraySize>  ClampMaxes = { false, false, false };
		for (int i = 0; i < DefaultValues.size(); ++i)
		{
			p.defaultValues[i] = DefaultValues[i];
			p.minSliders[i] = MinSliders[i];
			p.maxSliders[i] = MaxSliders[i];
			p.minValues[i] = MinValues[i];
			p.maxValues[i] = MaxValues[i];
			p.clampMins[i] = ClampMins[i];
			p.clampMaxes[i] = ClampMaxes[i];
		}
		OP_ParAppendResult res = manager->appendFloat(p, DefaultValues.size());

		assert(res == OP_ParAppendResult::Success);
	}


}

#pragma endregion
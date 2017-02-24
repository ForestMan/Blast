#include "MaterialAssignmentsPanel.h"
#include "ui_MaterialAssignmentsPanel.h"
#include "ProjectParams.h"
#include "RenderMaterial.h"
#include "SampleManager.h"
#include "MaterialLibraryPanel.h"

MaterialAssignmentsPanel* pMaterialAssignmentsPanel = nullptr;
MaterialAssignmentsPanel* MaterialAssignmentsPanel::ins()
{
	return pMaterialAssignmentsPanel;
}

MaterialAssignmentsPanel::MaterialAssignmentsPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MaterialAssignmentsPanel),
	_selectedGraphicsMesh(-1)
{
    ui->setupUi(this);
	pMaterialAssignmentsPanel = this;
	m_bValid = true;
}

void MaterialAssignmentsPanel::getMaterialNameAndPaths(std::vector<std::string>& materialNames, std::vector<std::string>& materialPaths)
{
	QString m1 = ui->comboBoxMaterialID1->currentText();
	QString m2 = ui->comboBoxMaterialID2->currentText();
	std::string name1 = m1.toUtf8().data();
	std::string name2 = m2.toUtf8().data();
	std::string path1 = "";
	std::string path2 = "";

	BPParams& projectParams = BlastProject::ins().getParams();
	BPPGraphicsMaterialArray& theArray = projectParams.graphicsMaterials;
	int count = theArray.arraySizes[0];
	for (int i = 0; i < count; ++i)
	{
		BPPGraphicsMaterial& item = theArray.buf[i];
		std::string name = item.name.buf;
		std::string path = item.diffuseTextureFilePath.buf;
		if (name1 == name)
		{
			path1 = path;
		}
		else if (name2 == name)
		{
			path2 = path;
		}
		else if (path1 != "" && path2 != "")
		{
			break;
		}
	}

	materialNames.push_back(name1);
	materialNames.push_back(name2);
	materialPaths.push_back(path1);
	materialPaths.push_back(path2);
}

MaterialAssignmentsPanel::~MaterialAssignmentsPanel()
{
    delete ui;
}

void MaterialAssignmentsPanel::updateValues()
{
	m_bValid = false;
	ui->comboBoxMaterialID1->clear();
	ui->comboBoxMaterialID2->clear();
	m_bValid = true;

	QStringList materialNames;
	materialNames.append("None");
	BPParams& projectParams = BlastProject::ins().getParams();
	BPPGraphicsMaterialArray& theArray = projectParams.graphicsMaterials;
	int count = theArray.arraySizes[0];
	for (int i = 0; i < count; ++i)
	{
		BPPGraphicsMaterial& item = theArray.buf[i];
		materialNames.append(item.name.buf);
	}

	m_bValid = false;
	ui->comboBoxMaterialID1->insertItems(0, materialNames);
	ui->comboBoxMaterialID2->insertItems(0, materialNames);
	m_bValid = true;
	
	SampleManager* pSampleManager = SampleManager::ins();
	if (pSampleManager == nullptr)
	{
		return;
	}

	BlastAsset* pBlastAsset = nullptr;
	int index = -1;
	pSampleManager->getCurrentSelectedInstance(&pBlastAsset, index);
	if (pBlastAsset == nullptr || index == -1)
	{
		return;
	}

	RenderMaterial* pRenderMaterial[] = { nullptr, nullptr };
	std::string strMaterialNames[] = { "None", "None" };
	bool ex[] = { true, false };
	for (int i = 0; i < 2; i++)
	{
		pSampleManager->getMaterialForCurrentFamily(&pRenderMaterial[i], ex[i]);
		if (pRenderMaterial[i] != nullptr)
		{
			std::string m = pRenderMaterial[i]->getMaterialName();
			if (m != "")
			{
				strMaterialNames[i] = m;
			}
		}
	}

	m_bValid = false;
	ui->comboBoxMaterialID1->setCurrentText(strMaterialNames[0].c_str());
	ui->comboBoxMaterialID2->setCurrentText(strMaterialNames[1].c_str());
	m_bValid = true;
	
	return;

	if (_selectedGraphicsMesh > -1)
	{
		BPParams& projectParams = BlastProject::ins().getParams();
		BPPBlast& blast = projectParams.blast;
		BPPGraphicsMaterialArray& graphicsMaterialsArray = projectParams.graphicsMaterials;

		BPPMaterialAssignments& assignment = blast.graphicsMeshes.buf[_selectedGraphicsMesh].materialAssignments;

		ui->comboBoxMaterialID1->clear();
		ui->comboBoxMaterialID2->clear();
		ui->comboBoxMaterialID3->clear();
		ui->comboBoxMaterialID4->clear();

		QStringList materialNames;
		materialNames.append("None");
		int count = graphicsMaterialsArray.arraySizes[0];
		for (int i = 0; i < count; ++i)
		{
			materialNames.append(graphicsMaterialsArray.buf[i].name.buf);
		}

		ui->comboBoxMaterialID1->insertItems(0, materialNames);
		ui->comboBoxMaterialID2->insertItems(0, materialNames);
		ui->comboBoxMaterialID3->insertItems(0, materialNames);
		ui->comboBoxMaterialID4->insertItems(0, materialNames);

		ui->comboBoxMaterialID1->setCurrentIndex(assignment.materialIndexes[0] + 1);
		ui->comboBoxMaterialID2->setCurrentIndex(assignment.materialIndexes[1] + 1);
		ui->comboBoxMaterialID3->setCurrentIndex(assignment.materialIndexes[2] + 1);
		ui->comboBoxMaterialID4->setCurrentIndex(assignment.materialIndexes[3] + 1);
	}


}

void MaterialAssignmentsPanel::on_comboBoxMaterialID1_currentIndexChanged(int index)
{
	if (index < 0 || !m_bValid)
		return;

	RenderMaterial* pRenderMaterial = nullptr;

	QString currentText = ui->comboBoxMaterialID1->currentText();
	std::string name = currentText.toUtf8().data();

	SampleManager* pSampleManager = SampleManager::ins();
	if (pSampleManager == nullptr)
	{
		return;
	}
	std::map<std::string, RenderMaterial*>& renderMaterials = pSampleManager->getRenderMaterials();
	std::map<std::string, RenderMaterial*>::iterator it = renderMaterials.find(name);
	if (it != renderMaterials.end())
	{
		pRenderMaterial = it->second;
	}
	else
	{
		MaterialLibraryPanel* pMaterialLibraryPanel = MaterialLibraryPanel::ins();
		std::map<std::string, RenderMaterial*>& renderMaterials2 = pMaterialLibraryPanel->getRenderMaterials();
		it = renderMaterials2.find(name);
		if (it != renderMaterials2.end())
		{
			pRenderMaterial = it->second;
		}
	}

	pSampleManager->setMaterialForCurrentFamily(pRenderMaterial, true);
	
	return;
	assignMaterialToMaterialID(0, index - 1);
}

void MaterialAssignmentsPanel::on_comboBoxMaterialID2_currentIndexChanged(int index)
{
	if (index < 0 || !m_bValid)
		return;

	RenderMaterial* pRenderMaterial = nullptr;

	QString currentText = ui->comboBoxMaterialID2->currentText();
	std::string name = currentText.toUtf8().data();

	SampleManager* pSampleManager = SampleManager::ins();
	if (pSampleManager == nullptr)
	{
		return;
	}
	std::map<std::string, RenderMaterial*>& renderMaterials = pSampleManager->getRenderMaterials();
	std::map<std::string, RenderMaterial*>::iterator it = renderMaterials.find(name);
	if (it != renderMaterials.end())
	{
		pRenderMaterial = it->second;
	}
	else
	{
		MaterialLibraryPanel* pMaterialLibraryPanel = MaterialLibraryPanel::ins();
		std::map<std::string, RenderMaterial*>& renderMaterials2 = pMaterialLibraryPanel->getRenderMaterials();
		it = renderMaterials2.find(name);
		if (it != renderMaterials2.end())
		{
			pRenderMaterial = it->second;
		}
	}

	pSampleManager->setMaterialForCurrentFamily(pRenderMaterial, false);

	return;
	assignMaterialToMaterialID(1, index - 1);
}

void MaterialAssignmentsPanel::on_comboBoxMaterialID3_currentIndexChanged(int index)
{
	assignMaterialToMaterialID(2, index - 1);
}

void MaterialAssignmentsPanel::on_comboBoxMaterialID4_currentIndexChanged(int index)
{
	assignMaterialToMaterialID(3, index - 1);
}

void MaterialAssignmentsPanel::assignMaterialToMaterialID(int materialID, int materialIndex)
{
	if (materialID < 0 || materialID > 3 || materialIndex < 0)
		return;

	BPParams& projectParams = BlastProject::ins().getParams();
	BPPGraphicsMaterialArray& graphicsMaterialArray = projectParams.graphicsMaterials;
	BPPBlast& blast = projectParams.blast;

	if (materialIndex >= graphicsMaterialArray.arraySizes[0])
		return;

	BPPGraphicsMeshArray& graphicsMeshArray = blast.graphicsMeshes;

	if (_selectedGraphicsMesh > -1 && _selectedGraphicsMesh < graphicsMeshArray.arraySizes[0])
	{
		graphicsMeshArray.buf[_selectedGraphicsMesh].materialAssignments.materialIndexes[materialID] = materialIndex;
	}
}
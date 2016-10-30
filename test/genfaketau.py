#!/usr/bin/env python

import math
import matplotlib.pyplot as plt
# import pandas as pd
import numpy as np
from root_pandas import read_root

numbers_in = ['nloosetaus', 'ntighttaus', 'nfaketaus', 'nfaketighttaus', 'nrealtaus', 'nrealtighttaus']
numbers = read_root("test/genfaketau/out/ntuple.root", "ttjets", columns=numbers_in)

fig = plt.figure()
numbers.plot.hist(
    stacked=False,
    subplots=True,
    layout=(3, 2),
    sharey=True,
    ylim=(.5, 1e5),
    logy=True,
    figsize=(8.5, 11),
    grid=True
)
for ax in fig.get_axes():
    ax.set_yscale('log', nonposy='clip')
plt.savefig('jetfakes_numbers.png')

taus_in = 'pt eta isoMVA03 genjet_pt genjet_eta genjet_chargedpt genjet_chargedeta match genjet_constituents genjet_chargedconstituents genjet_neutralconstituents genjet_closestpt genjet_closestdr pfake pjet genjet_signalpt genjet_signalconstituents genjet_signalchargedpt genjet_signalchargedconstituents genjet_isopt genjet_isoconstituents genjet_isochargedpt genjet_isochargedconstituents antiElectron antiMuon'
taus_in = ['tau_' + v for v in taus_in.split()]
taus = read_root("test/genfaketau/out/ntuple.root", "ttjets", columns=taus_in, flatten=True)

gen_in = 'chargedconstituents neutralconstituents constituents chargedpt pt eta pjet pfake closestpt closestdr isopt isoconstituents isochargedpt isochargedconstituents signalpt signalconstituents signalchargedpt signalchargedconstituents'
gen_in = ['genjet_' + v for v in gen_in.split()]
alljets = read_root("test/genfaketau/out/ntuple.root", "ttjets", columns=gen_in, flatten=True)
jets = alljets[
    (alljets.genjet_pt > 18)
    & (alljets.genjet_eta > -2.5)
    & (alljets.genjet_eta < 2.5)
    & (alljets.genjet_constituents <= 20)
    & (alljets.genjet_isoconstituents <= 11)
    & (alljets.genjet_signalpt > 15)
]

print "before", len(alljets)
print "after", len(jets)

fakes = taus[(taus.tau_match == 6)]
selection = taus[
    (taus.tau_match == 6)
    & (taus.tau_isoMVA03 >= 5)
    & (taus.tau_antiElectron >= 3)
    & (taus.tau_antiMuon >= 3)
    & (taus.tau_pt >= 20.)
]

print "fakes before", len(fakes)
print "fakes after", len(selection)

pt_binning = range(0, 150, 10) + [10000]
const_binning = range(0, 15) + [10000]

with open('src/FakeData.frag', 'w') as dumpf:
    def dump(name, bins, edges):
        fmt = "std::vector<double> {}{{{}}};\n"
        dumpf.write(fmt.format(name + "_bins", ", ".join(map(str, bins))))
        dumpf.write(fmt.format(name + "_edges", ", ".join(map(str, edges[:-1]))))

    bins, edges = np.histogram(selection.tau_genjet_pt, bins=pt_binning, density=True)
    dump("fake_pt", bins, edges)
    bins, edges = np.histogram(selection.tau_genjet_chargedpt, bins=pt_binning, density=True)
    dump("fake_charged_pt", bins, edges)
    bins, edges = np.histogram(selection.tau_genjet_constituents, bins=const_binning, density=True)
    dump("fake_constituents", bins, edges)
    bins, edges = np.histogram(selection.tau_genjet_chargedconstituents, bins=const_binning, density=True)
    dump("fake_charged_constituents", bins, edges)

    bins, edges = np.histogram(jets.genjet_pt, bins=pt_binning, density=True)
    dump("jet_pt", bins, edges)
    bins, edges = np.histogram(jets.genjet_chargedpt, bins=pt_binning, density=True)
    dump("jet_charged_pt", bins, edges)
    bins, edges = np.histogram(jets.genjet_constituents, bins=const_binning, density=True)
    dump("jet_constituents", bins, edges)
    bins, edges = np.histogram(jets.genjet_chargedconstituents, bins=const_binning, density=True)
    dump("jet_charged_constituents", bins, edges)

labels = ['genjets', u'genjet fakes']
pspace = [
    ('pt', range(0, 201, 5)),
    ('eta', np.array(range(-50, 51, 2)) * 0.1),
    ('chargedpt', range(0, 201, 5)),
    ('constituents', range(0, 31, 1)),
    ('chargedconstituents', range(0, 31, 1)),
    ('neutralconstituents', range(0, 31, 1)),
    ('isoconstituents', range(0, 31, 1)),
    ('signalconstituents', range(0, 31, 1)),
    ('isochargedconstituents', range(0, 31, 1)),
    ('signalchargedconstituents', range(0, 31, 1)),
    ('isopt', range(0, 26, 1)),
    ('signalpt', range(0, 101, 2)),
    ('isochargedpt', range(0, 26, 1)),
    ('signalchargedpt', range(0, 101, 2)),
    ('closestpt', range(0, 201, 5)),
    ('closestdr', np.array(range(41)) * 0.05 * math.pi)
]

for name, nbins in pspace:
    print 'Processing', name
    fig = plt.figure()
    n, bins, patches = plt.hist([jets['genjet_' + name], selection['tau_genjet_' + name]], bins=nbins, normed=1)
    plt.legend(patches, labels)
    plt.savefig('jetfakes_genjet_{}.png'.format(name))

# Probability for fakes/jet

nbins = 30

fig = plt.figure()
n, bins, patches = plt.hist([jets.genjet_pfake, selection.tau_pfake], bins=nbins, normed=1)
plt.legend(patches, labels)
plt.savefig('jetfakes_genjet_pfake.png')

fig = plt.figure()
n, bins, patches = plt.hist([jets.genjet_pjet, selection.tau_pjet], bins=nbins, normed=1)
plt.legend(patches, labels)
plt.savefig('jetfakes_genjet_pjet.png')

nbins = range(31)

fig = plt.figure()
n, bins, patches = plt.hist([jets.genjet_pfake / jets.genjet_pjet, selection.tau_pfake / selection.tau_pjet], bins=nbins, normed=1)
plt.legend(patches, labels)
plt.savefig('jetfakes_genjet_pfake_over_pjet.png')

nbins = [range(0, 100, 5), range(0, 20, 1)]

fig = plt.figure()
plt.hist2d(jets.genjet_chargedpt, jets.genjet_chargedconstituents, bins=nbins)
plt.xlabel('genjet charged pt')
plt.ylabel('genjet charged constituents')
plt.savefig('genjet_chargedpt_vs_chargedconstituents.png')

fig = plt.figure()
plt.hist2d(selection.tau_genjet_chargedpt, selection.tau_genjet_chargedconstituents, bins=nbins)
plt.xlabel('fake tau charged pt')
plt.ylabel('fake tau charged constituents')
plt.savefig('faketau_chargedpt_vs_chargedconstituents.png')

fig = plt.figure()
plt.hist2d(jets.genjet_pt, jets.genjet_constituents, bins=nbins)
plt.xlabel('genjet pt')
plt.ylabel('genjet constituents')
plt.savefig('genjet_pt_vs_constituents.png')

fig = plt.figure()
plt.hist2d(selection.tau_genjet_pt, selection.tau_genjet_constituents, bins=nbins)
plt.xlabel('fake tau pt')
plt.ylabel('fake tau constituents')
plt.savefig('faketau_pt_vs_constituents.png')

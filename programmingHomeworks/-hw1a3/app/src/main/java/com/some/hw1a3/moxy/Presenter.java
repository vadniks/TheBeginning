package com.some.hw1a3.moxy;


import com.arellomobile.mvp.InjectViewState;
import com.arellomobile.mvp.MvpPresenter;
import com.example.rumpilstilstkin.lesson1.R;

@InjectViewState
public class Presenter extends MvpPresenter<MoxyExampleView> {

    private Model mModel;

    @Override
    public void attachView(MoxyExampleView view) {
        super.attachView(view);
        if (mModel == null) {
            mModel = new Model();
        }
    }

    private int calcNewModelValue(int modelElementIndex) {
        int currentValue = mModel.getElementValueAtIndex(modelElementIndex);
        return currentValue + 1;
    }

    public void buttonClick(final int btnIndex) {
        int newModelValue;
        switch (btnIndex) {
            case R.id.btnCounter1:
                newModelValue = calcNewModelValue(0);
                mModel.setElementValueAtIndex(0, newModelValue);
                getViewState().setButtonText(1, newModelValue);
                break;
            case R.id.btnCounter2:
                newModelValue = calcNewModelValue(1);
                mModel.setElementValueAtIndex(1, newModelValue);
                getViewState().setButtonText(2, newModelValue);
                break;
            case R.id.btnCounter3:
                newModelValue = calcNewModelValue(2);
                mModel.setElementValueAtIndex(2, newModelValue);
                getViewState().setButtonText(3, newModelValue);
                break;
        }
    }
}
